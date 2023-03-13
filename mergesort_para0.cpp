#include <iostream>
#include <vector>
#include <pthread.h>
#include <queue>

#define MAX_THREAD 4

using namespace std;

int n, arr[100];


void merge(int arr[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], M[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
        }
            k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

pair<int, int> get_segment(int n, int id){
    int length = n / MAX_THREAD;
    return {id * length, id == MAX_THREAD - 1 ? n - 1 : (id + 1) * length - 1};
}
void* threaded_mergeSort(void* arg){
    int thread_id = *((int*)(&arg));
    int left = get_segment(n, thread_id).first;
    int right = get_segment(n, thread_id).second;
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, right);
        mergeSort(arr, left + 1, right);
        merge(arr, left, middle, right);
    }
    return NULL;
}
vector<int> st;
void* threaded_merge(void* arg){
    vector<int> arg1 = st;
    int left = arg1[0];
    int middle = arg1[1];
    int right = arg1[2];
    merge(arr, left, middle, right);
    return NULL;
}
pthread_t threadsm[MAX_THREAD * 10];
void mergeParts(int n){
    vector<pair<int, int>> cp = {};
    int length = (n + MAX_THREAD - 1) / MAX_THREAD;
    for (int i = 0; i < MAX_THREAD; i++)
        cp.push_back(get_segment(n, i));
    int d = 0;
    while (cp.size() != 1){
        vector<pair<int, int>> cp_tmp = {};
        int d1 = d;
        for (int i = 0; i + 1 < cp.size(); i += 2){
            st = {cp[i].first, cp[i].second, cp[i + 1].second};
            pthread_create(&threadsm[d++], NULL, threaded_merge, NULL);
            pthread_join(threadsm[d - 1], NULL);
            cp_tmp.push_back({cp[i].first, cp[i + 1].second});
        }
        if (cp.size() % 2)
            cp_tmp.push_back(cp.back());
        cp = cp_tmp;
    }
}
bool check(int arr[], int l, int r){
    for (int i = l; i < r; i++)
        if (arr[i] > arr[i + 1]) return 0;
    return 1;
}

void parallel_merge_sort(int arr[], int l, int r){
    pthread_t threads[MAX_THREAD];
    for (int i = 0; i < MAX_THREAD; i++)
        pthread_create(&threads[i], NULL, threaded_mergeSort, (void *)i);
    for (int i = 0; i < MAX_THREAD; i++)
        pthread_join(threads[i], NULL);
    mergeParts(n);
}
void original_merge_sort(int arr[], int l, int r){
    mergeSort(arr, l, r);
}
int main(){
    cin >> n;
    for (int i = 0; i < n ;i++)
        cin >> arr[i];
    // 5
    // 3 4 3 1 2
    parallel_merge_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " \n"[i == n - 1];
    cout << check(arr, 0, n - 1);
}

