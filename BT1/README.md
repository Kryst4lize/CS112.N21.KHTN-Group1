# CS112.N21.KHTN---Parallel-Algorithm
## Danh sách các file
Sort.h : Chứa các hàm cần thiết thực hiện 
mergesort_para0.cpp : file thực hiện 


## Kiểm thử
# Tính đúng đắn: 
- Chạy với mảng ngẫu nhiên 100,000 phần tử (số nguyên), 100 lần, đều cho kết quả đúng, kết luận, có thể xem như thuật toán là đúng.
# Thời gian chạy:
Chạy thử cho kết quả sau (A/B nghĩa là mảng ngẫu nhiên A phần tử, chạy B lần):
||100/100000|1000/10000|10000/1000|100000/100|
|---|---|---|---|---|
|merge sort|4120.24|6213.36|7644.44|8979.51|
|parallel merge sort|58492.3|8882.51|4536.26|4062.23|


Thực tế cho thấy, với số phần tử lớn, parallel merge sort sẽ chạy nhanh hơn, nhưng với số phần tử nhỏ, merge sort lại ổn hơn nhiều, lí do là vì việc tạo, quản lí các luồng rất tốn thời gian.
