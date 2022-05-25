//ĐỀ BÀI

// Tren một nền phẳng đã được chia thành các lưới ô vuông đơn vị gồm mxn ô (m, n ≤ 100),
// người ta đặt chồng khít lên nhau các khối lập phương đơn vị thành những cột. Khối dưới cùng của cột chiếm trọn một ô của lưới. Chiều cao của mỗi cột được tính bằng số khối lập phương đơn vị tạo thành cột đó. Sau khi xếp xong toàn bộ các cột, người ta tiến hành sơn các mặt nhìn thấy được của các cột.
// Yêu cầu: Biết chiều cao của mỗi cột, hãy tính số đơn vị diện tích cần sơn.

// Dữ liệu vào đặt trong file văn bản PAINT.INP. Trong đó:
// Dòng đầu tiên ghi hai số nguyên dương m, n là kích thước của lưới nền (m hàng, n cột) m dòng tiếp theo, dòng thứ i ghi n số nguyên không âm, số nguyên thứ j biểu thị chiều cao của cột dựng tại ô (i, j) của lưới. Các số cách nhau ít nhất một dấu cách.

// Kết quả ra đặt trong file văn bản PAINT.OUT, ghi số diện tích cần sơn.

#include <iostream>
// đọc file và gán vào mảng
void readFile(int &m, int &n, int arr[1000][1000])
{
    FILE *f = fopen("PAINT.INP", "rt");
    fscanf(f, "%d", &m);
    fscanf(f, "%d", &n);
    for (int i = 0; i < m + 2; i++)
    {
        for (int j = 0; j < n + 2; j++)
        {
            if (i == 0 || i == m + 1 || j == 0 || j == n + 1)
                arr[i][j] = 0;
            else
                fscanf(f, "%d", &arr[i][j]);
        }
    }
    fclose(f);
}

void paint(int m, int n, int arr[1000][1000])
{
    int s = m * n;
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        { // tìm số mặt bên trên
            if (arr[i][j] > arr[i - 1][j])
                s += (arr[i][j] - arr[i - 1][j]);
            // tìm số mặt bên dưới
            if (arr[i][j] > arr[i + 1][j])
                s += (arr[i][j] - arr[i + 1][j]);
            //  tìm số mặt bên trái
            if (arr[i][j] > arr[i][j - 1])
                s += (arr[i][j] - arr[i][j - 1]);
            // tìm số mặt bên phải
            if (arr[i][j] > arr[i][j + 1])
                s += (arr[i][j] - arr[i][j + 1]);
        }
    }
    // Kết quả được cộng dồn vào biến s chưa tất cả các đỉnh đã được sơn cột
    FILE *f = fopen("PAINT.OUT", "wt");
    fprintf(f, "%d", s);
    fclose(f);
}

int main()
{
    int m, n, arr[1000][1000];
    std::cout << "Bai 029 running...\n";
    readFile(m, n, arr);
    paint(m, n, arr);
    std::cout << "Success...\n";
    return 0;
}
