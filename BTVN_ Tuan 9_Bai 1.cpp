#include<iostream>
#include<ctime>

using namespace std;

struct NODE // Khởi tạo cấu trúc 1 node lưu thông tin file
{
    string name;
    string address;
    float size;
    char* time;
    NODE* link;
};

struct LIST // Khởi tạo cấu trúc của 1 folder
{
    NODE* first;
    NODE* last;
};
void LIST_INIT(LIST* d) 
{
    d->first = d->last = NULL; // Danh sách rỗng

}

// Hàm tạo 1 node
NODE* MAKE_NODE(string name, string adr, float s, char* dt) 
{
    NODE* p = new NODE; // Gán địa chỉ của một node mới cho p
    if (p == NULL) return NULL; // Kiểm tra xem có tạo được node mới không
    p->name = name;
    p->address = adr;
    p->size = s;
    p->time = dt;
    cout << p->time;
    p->link = NULL;

    return p; // Trả về con trỏ p trỏ đến node được tạo
}

// Thêm node vào danh sách
void ADD_NODE(LIST* ds, NODE* p)
{
    if (ds->first == NULL) 
    {   // Danh sách rỗng
        ds->first = ds->last = p; // Con trỏ đầu tiên và con trỏ cuối cùng đều trỏ đến node mới p
    }
    else
    {
        ds->last->link = p; // Kết nối node mới vào cuối danh sách
        ds->last = p;       // Cập nhật con trỏ last
    }
}

// Thêm node với hệ số và số mũ cho trước
void ATTACH_NODE(LIST* lDT, string n, string adr, float s, char* dt)
{
    NODE* pDT = MAKE_NODE(n, adr, s, dt);
    if (pDT == NULL) return; // Kiểm tra nếu không tạo được node mới
    ADD_NODE(lDT, pDT); // Thêm node vào danh sách
}

// Hàm chọn file muốn sao chép từ thư mục C sang D
NODE* PICK(LIST* C, NODE* T)
{
    T = C->first;
    for(;;)
    {
        int check = 0; 
        cout << T->name;
        cin >> check;
        if(check == 0) break;
    }

    return T;
}

// Hàm sao chép file đã chọn từ C sang D
void COPY(LIST* D, LIST* C, NODE* T)
{
    PICK(C, T);
    D->last->link = T;
    D->last = T;
}

// Hàm tính tổng kích thước các file trong thư mục D
float CAL(LIST* D)
{
    float a = D->first->size;
    NODE* p = D->first->link;
    for(;;)
    {
        if(p != NULL)
        {
            a = a + p->size;
            p = p->link;
        }
        else break;
    }
    
    return a;
}

// Hàm sắp xếp lại danh sách theo kích thước
void SORT_BY_SIZE(LIST* D, NODE* T)
{
    int count = 0;
    T = D->first;
    for(;;)
    {
        if(T != NULL)
        {
            count++;
            T = T->link;
        }
        else break;
    }
    T = D->first;
    for(int i = 0; i < count; i++)
    {
        for(int j = i + 1; j < count; j++)
        {
            if(T->size > T->link->size)
            {
                D->first = T->link;
                T->link = T->link->link;
                D->first->link = T;
            }
        }
    }
}

// Hàm xóa bớt các file có ít dung lượng nhất cho tới khi kích thước của folder <= 32 Gb
void SOL(LIST* D)
{
    float a;
    a = CAL(D);
    for(;;)
    {
        if(a > 32) 
        {
            NODE* p = D->first;
            D->first = D->first->link;

            delete p;
        }
        else break;
    }
}

int main()
{
    time_t now = time(0);
    char* dt = ctime(&now);

    LIST D;
    LIST C;  
    
    return 0;
}
