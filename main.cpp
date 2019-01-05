#include <iostream>
#include<fstream>
#include<cstring>
#include<cstdio>
using namespace std;


int No = 0;//设置一个全局变量来进行合同号的自动更改
class Contract{
public:
    int no,first, second, thirda, thirdb, forth, fifth, sixth;
    string filename;
    string Name;//合同名称
    string status;//合同状态
    string partnera,partnerb;//合同方
    double fund;//款项
    string text;//正文

    Contract(const string fn, const string n, const string s, const string pa, const string pb, const double f, const string t) : filename(fn), Name(n), status(s), partnera(pa), partnerb(pb), fund(f), text(t){
        No++;
        no = No;
        ofstream outfile("/Users/apple/Desktop/Contract/"+fn, ios::out);
        if (!outfile){
            cout << "不能打开输入文件\n";
            exit(1);
        }
        outfile << "Name of Contract:" << "";
        first = (int)outfile.tellp();
        outfile.seekp(100L, ios::cur);
        outfile.seekp(first,ios::beg);
        outfile << Name << "\n";
        outfile.seekp(first + 100, ios::beg);
        
        outfile << "Contract Status:" << "";
        second = (int)outfile.tellp();
        outfile.seekp(30L, ios::cur);
        outfile.seekp(second, ios::beg);
        outfile << status << "\n";
        outfile.seekp(second + 30, ios::beg);

        outfile << "Contract Party:" << "\n";
        outfile << "partnerA:" << "\n";
        thirda = (int)outfile.tellp();
        outfile.seekp(50L, ios::cur);
        outfile << "partnerB:" << "\n";
        thirdb = (int)outfile.tellp();
        outfile.seekp(50L, ios::cur);
        outfile.seekp(thirda,ios::beg);
        outfile << partnera << "\n";
        outfile.seekp(thirdb,ios::beg);
        outfile << partnerb << "\n";
        outfile.seekp(thirdb + 50, ios::beg);
        
        outfile << "Fund:" << "";
        forth =(int)outfile.tellp();
        outfile.seekp(20L, ios::cur);
        outfile.seekp(forth,ios::beg);
        outfile << fund << "\n";
        outfile.seekp(forth + 20, ios::beg);
        
        outfile << "Contract Number:" << "";
        fifth =(int)outfile.tellp();
        outfile.seekp(20L, ios::cur);
        outfile.seekp(fifth,ios::beg);
        outfile << no << "\n";
        outfile.seekp(fifth + 20, ios::beg);
        
        outfile << "Text:" << "";
        sixth =(int)outfile.tellp();
        outfile.seekp(sixth,ios::beg);
        outfile << t << "\n";
        outfile.seekp(0, ios::beg);
        
        outfile.close();
    }
    void reName(){
        //当文件以读写方式打开时，可以利用seekp和seekg来对文件进行修改和读取
        fstream outfile("/Users/apple/Desktop/Contract/"+filename, ios::out | ios::in);
        //修改合同名
        outfile.seekp(first, ios::beg);
        for (int i = 0; i < 99; i++){
            outfile << " ";
        }
        
        outfile << "\n";
        outfile.seekp(first, ios::beg);
        cout << "Please input the new Contract name :" << endl;
        char cn[100] = "";
        for(int i = 0; i < 100; i++){

            scanf("%c", &cn[i]);
            if(cn[i] == '!'){
                cn[i] = '\n';
                break;
            }
        }
        
        outfile.seekp(first, ios::beg);
        outfile << cn;
        outfile.close();
    }
    void reStatus(){
        fstream outfile("/Users/apple/Desktop/Contract/"+filename, ios::out | ios::in);
        //修改合同状态
        cout << "Please choose the new status :" << endl;
        cout << "1.评审  2.签订  3.执行" << endl;
        outfile.seekp(second, ios::beg);
        int x;
        cin >> x;
        if(x == 1){
            outfile << "评审" ;
            status = "评审";
        }
        else if(x == 2){
            outfile << "签订" ;
            status = "签订";
        }
        else if(x == 3){
            outfile << "执行" ;
            status = "执行";
        }
        outfile.close();
    }
    void rePartner(){
        fstream outfile("/Users/apple/Desktop/Contract/"+filename, ios::out | ios::in);
        //修改合同方
        outfile.seekp(thirda, ios::beg);
        for (int i = 0; i < 49; i++){
            outfile << " ";
        }
        outfile << "\n";
        outfile.seekp(thirda, ios::beg);
        cout << "Please input the new partnera :" << endl;
        char cpa[50];
        string Cpa;
        cin >> Cpa;
        for(int i = 0 ;i < 50; i++){
            cpa[i] = Cpa[i];
        }
        outfile << cpa;
        outfile.seekp(thirdb, ios::beg);
        for (int i = 0; i < 49; i++){
            outfile << " ";
        }
        outfile << "\n";
        outfile.seekp(thirdb, ios::beg);
        cout << "Please input the new partnerb :" << endl;
        char cpb[50];
        string Cpb;
        cin >> Cpb;
        for(int i = 0 ;i < 50; i++){
            cpb[i] = Cpb[i];
        }
        outfile << cpb;
        outfile.close();
        
    }
    void refund(){
        fstream outfile("/Users/apple/Desktop/Contract/"+filename, ios::out | ios::in);
        //修改款项
        cout << "Please input the new fund :" << endl;
        int cf;
        cin >> cf;
        fund = cf;
        outfile.seekp(forth, ios::beg);
        outfile << cf;
        outfile << "\n";
        outfile.close();
    }
    void retext(){
        fstream outfile("/Users/apple/Desktop/Contract/"+filename, ios::out | ios::in);
        //修改正文
        outfile.seekp(0, ios::end);
        int len = 0;
        len = (int)outfile.tellp();
        cout << len;
        outfile.seekp(sixth, ios::beg);
        for(int i = 0; i < len-sixth; i++){
            outfile << " ";
        }
        outfile << "\n";
        cout << "Please input the new text :" << endl;
        char ct[100] = "";
        
        for(int i = 0;i < 1000; i++){
            scanf("%c", &ct[i]);
            if(ct[i] == '!'){
                ct[i] = '\n';
                break;
            }
        }
        cout << ct;
        text = ct;
        outfile.seekp(sixth, ios::beg);
        outfile << ct;
        outfile.close();
    }
    
    
    //读取文件并输出
    void Read(){
        int length;
        ifstream infile("/Users/apple/Desktop/Contract/"+filename, ios::in);
        if(!infile.is_open()){
            cout << "Error opening infile";
            exit(1);
        }
        infile.seekg(0, ios::end);
        length = (int)infile.tellg();
        infile.seekg(0, ios::beg);
        char* buffer = new char[length];
        infile.read(buffer,length);
        infile.close();
        for(int i = 0; i < length; i++){
            printf("%c", buffer[i]);
        }
    }
    
};


struct Node{
    Node *next;
    Contract *data;//使Contract结构体指针作为链表的一个数据域
    int _data;
};
class list{
public:
    Node *header;
    Node *cur;
    Node *prev;
    list(){
        header = new Node;
        //other = new Node;
        cur = new Node;
        //other = header;
        cur = header;
        prev = header;
    }
    
    //文件初始化函数
    void init(){
        Node *other = header;

        string fn, n, s, pa, pb, t;
        double f;
        cout << "文件名：" << "\n";
        cin >> fn;
        cout << "合同名称：" << "\n";
        char cn[100] = "";
        for(int i = 0; i < 100; i++){
            scanf("%c", &cn[i]);
            if(cn[i] == '!'){
                cn[i] = '\n';
                break;
            }
        }
        n = cn;
        int x;
        cout << "合同状态：" << "\n" << "1.评审  " << "2.签订  " << "3.执行  " << "\n" ;
        cin >> x;
        if(x == 1){
            s = "评审";
        }
        else if(x == 2){
            s = "签订";
        }
        else if(x == 3){
            s = "执行";
        }
        cout << "合作方A：" << "\n";
        cin >> pa ;
        cout << "合作方B：" << "\n";
        cin >> pb;
        cout << "款项：" << "\n";
        cin >> f;
        cout << "正文：" << endl;
        char ct[100] = "";
        for(int i = 0;i < 1000; i++){
            scanf("%c", &ct[i]);
            if(ct[i] == '!'){
                ct[i] = '\n';
                break;
            }
        }
        t = ct;
        other = cur;
        other->data = new Contract(fn, n, s, pa, pb, f, t);
        other->_data = No;
        cur->next = new Node;
        cur = cur->next;
        prev = header;
    }
    
    
    
    
    //通过合同号查找函数
    void nfind(int x){
        int n = No;
//        other = header;
//        while(other->next != NULL){   //计算出链表的长度
//            other = other->next;
//            n = n + 1;
//        }
//        cout << n;
        Node *other = header;
        for(int i = 0;i < n ; i++){
            if(other->_data == x){
                other->data->Read();
                break;
            }
            if(other->next == NULL){
                break;
            }
            other = other->next;
            
        }
    }
    
    //通过状态查找函数
    void sfind(int x){
        int n = 0;
        Node* other = new Node;
        other = header;
        while(other->next != NULL){   //计算出链表的长度
            other = other->next;
            n = n + 1;
        }
        other = header;
        if(x == 1){
            for(int i = 0;i < n ; i++){
                if(other->data->status == "评审")
                    other->data->Read();
                cout << "\n";
                other = other->next;
            }
        }
        else if(x == 2){
            for(int i = 0;i < n ; i++){
                if(other->data->status == "签订")
                    other->data->Read();
                cout << "\n";
                other = other->next;
            }
        }
        else if(x == 3){
            for(int i = 0;i < n ; i++){
                if(other->data->status == "执行")
                    other->data->Read();
                cout << "\n";
                other = other->next;
            }
        }
    }
    
    
    //通过合同号排序并按顺序输出合同名称
    void sort(){
        Node *pre, *p, *tail;
        Node *other = header;
        tail=NULL;
        pre=header;
        other = header;
        int n = 0;          //用于记录链表的长度
        while(other->next != NULL){   //计算出链表的长度
            other = other->next;
            n = n + 1;
        }
        other = header;
        for(int  i =  0; i < n; i++){
            p=header->next;
            pre=header;
            while(p->next!=tail)
            {
                if((p->_data)>(p->next->_data))
                {
                    pre->next=p->next; //交换节点方法一
                    p->next = p->next->next;
                    pre->next->next = p;
                    p = pre->next;
    
                }
                p=p->next;  //p再前进一个节点
                pre=pre->next;
            }
        }
       
        for(int i = 0; i < n ;i++){
            cout << other->data->Name << "\n";
            other = other->next;
        }
        cout << endl;
        other = header;
        
    }

    
    //删除合同
    void Remove(int x){
        Node *other = header;
        while(other->_data != x){
            other = other->next;
        }
        string Fn;
        Fn = "/Users/apple/Desktop/Contract/" + other->data->filename;
        char * filename = new char[100];
        for(int i = 0; i < 100; i++){
            filename[i] = Fn[i];
        }
        other = header;
        
        remove(filename);
        
        removepoint(x);
    }
    
    void removepoint(int x){
        Node* other;
        other = header;
        int n = 0;          //用于记录链表的长度
        while(other != NULL){   //计算出链表的长度
            other = other->next;
            n = n + 1;
        }
        other = header;//初始化
        while(other->_data != x){//对链表从头到尾遍历，每当读取到与输入的数相同的数就执行删除操作
            if(other->_data == x){
                cout << header->_data;
                cout << header->next->_data;
                while (prev->next != other) {
                    prev = prev->next;
                }
                prev->next = other->next;
                x++;
                delete other;
                break;
            }
            other = other->next;
        }
    }
    
    //修改合同号
    void change(int x, int cdata){
        //先找到要更改合同号的节点
        int n = No;
//        other = header;
//        while(other != NULL){   //计算出链表的长度
//            other = other->next;
//            n = n + 1;
//        }
        
        Node *other = header;
        for(int i = 0;i < n ; i++){
            if(other->_data == x){
                break;
            }
            cout << "\n";
            if(other->next == NULL){
                break;
            }
            other = other->next;
        }
        Node *linshi = other;
        int j = 1;
        for(int i = 0;i < n ; i++){
            if(other->_data == cdata && other != linshi){
                cout << "所要更改的合同号重复，请更换" << endl;
                j = 0;
                break;
            }
            other = other->next;
        }
        if(j){
            other = linshi;
            other->_data = cdata;
            other->data->no = cdata;
            fstream outfile("/Users/apple/Desktop/Contract/"+other->data->filename, ios::out | ios::in);
            outfile.seekp(other->data->fifth,ios::beg);
            outfile << other->data->no;
            outfile.close();
            if(cdata > No){//为了之后建立文件时自动增加合同号不会与之前的合同号重复
                No = cdata;
            }
        }
        
    }
    
    
    void menu(){
        int l = 0;
        int g = 0;
        Node *other = header;
        while(l == 0){
            cout << "1.新增合同" << "\n" << "2.删除合同" << "\n" << "3.修改合同\n" << "4.查询合同\n" << "5.合同排序\n" << "6.结束" << "\n";
            cin >> g;
            switch (g) {
                case 1:
                    init();
                    break;
                case 2:
                    cout << "请输入想删除的合同的合同号" << endl;
                    int r;
                    cin >> r;
                    Remove(r);
                    break;
                case 3:
                    cout << "请输入要修改的合同号" << endl;
                    int p;
                    cin >> p;
                    other = header;
                    while(other->_data != p){
                        other = other->next;
                    }
                    cout << "1.修改合同名称\n" << "2.修改合同状态\n" << "3.修改合作方\n" << "4.修改款项\n" << "5.修改正文\n" << "6.修改合同号\n"<< "7.全部修改\n" << endl;
                    int h;
                    cin >> h;
                    if(h == 1)
                        other->data->reName();
                    else if(h == 2)
                        other->data->reStatus();
                    else if(h == 3)
                        other->data->rePartner();
                    else if(h == 4)
                        other->data->refund();
                    else if(h == 5)
                        other->data->retext();
                    else if(h == 6){
                        cout << "请分别输入想要修改的合同号和将该合同号修改称的数据" << endl;
                        int x,y;
                        cin >> x >> y;
                        change(x, y);
                    }
                    else if(h == 7){
                        other->data->reName();
                        other->data->reStatus();
                        other->data->rePartner();
                        other->data->refund();
                        other->data->retext();
                        cout << "请分别输入想要修改的合同号和将该合同号修改称的数据" << endl;
                        int X,Y;
                        cin >> X >> Y;
                        change(X, Y);
                    }
                    break;
                case 4:
                    int t;
                    cout << "1.通过合同号查询  " << "2.通过合同状态查询" << endl;
                    cin >> t;
                    if(t == 1){
                        int d;
                        cout << "请输入所要查询的合同号" << endl;
                        cin >> d;
                        nfind(d);
                    }
                    if(t == 2){
                        int o;
                        cout << "1.评审  " << "2.签订  " << "3.执行  " << endl;
                        cin >> o;
                        sfind(o);
                    }
                    break;
                case 5:
                    sort();
                    break;
                case 6:
                    l = 1;
                    break;
                default:
                    break;
            }
        }
    }
};
Node *cur = new Node;

int main(){
    list A;

    A.menu();
}
