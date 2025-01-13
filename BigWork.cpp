#include<bits/stdc++.h>
using namespace std;
map<string,vector<string> > Allbook;//这个是排序作者的书的~~~~~~~~~~~~~~~~
//map<string,vector<string> > Shudan;//每个用户的书单
map<string,int> Paiming;//排行榜
vector<string> newpbk;
class Start_Book{
	public:
		string ISBN,name,publisher,writer;//图书编码，书名，作业，出版社
		double price;
		int number;//数量
	string RISBN() const{
 		return ISBN;
	}
	string Rname() const{
		return name;
	}
	string Rpublisher() const{
		return publisher;
	}
	string Rwriter() const{
		return writer;
	}
	double Rprice() const{
		return price;
	}
	int Rnumber() const{
		return number;
	}

	void SetISBN(string &newISBN) {
		ISBN=newISBN;
	}
	void Setname(string &newname){
		name=newname;
	}
	void Setpublisher(string &newpublisher){
		publisher=newpublisher;
	}
	void Setwriter(string &newwriter){
		writer=newwriter;
	}
	void Setprice(double &newprice){
		price=newprice;
	}
	void Setnumber(int &newnumber){
		number=newnumber;
	}
	string Rbookmessage()const {
		string s=ISBN+"-"+name+"-"+publisher+"-"+writer+"-"+to_string(price)+"-"+to_string(number)+"-";
		return s;//返回书本的全部信息
	}
};

class User{
	public:
		string username;
		string userpassword;
	string Rusername(){
		return username;
	}
	string Ruserpassword(){
		return userpassword;
	}
	void Setusername(string &newusername){
		username=newusername;
	}
	void Setuserpassword(string newpassword){
		userpassword=newpassword;
	}
	string Rusermessage(){
		string s=username+"-"+userpassword+"-";
		return s;
	}
};
////////////////////////////////////////////////////////////////
vector<User> u_ser;
vector<Start_Book> b_ook;
int book_number=0,user_number=0;
////////////////////////////////////////////////////////////////
void readfileuser(){//从文件读取信息
	ifstream file("C:\\Users\\ppxiao019\\OneDrive\\Desktop\\User.txt");
	if(file.is_open()){
		string line;
		while (getline(file, line)) {  // 逐行读取文件
			stringstream ss(line);  // 使用 stringstream 进行字符串流处理
			string username, userpassword;
			getline(ss, username, '-');
			getline(ss, userpassword, '-');
			// 创建一个新的 User 对象并填充数据
			User user;
			user.Setusername(username);
			user.Setuserpassword(userpassword);
			// 将新用户对象添加到 u_ser 容器中
			u_ser.push_back(user);
		}
		cout<<"文件读取完毕"<<endl;
		file.close();  // 关闭文件
	}
}

void updatefileuser(){//写入信息
	ofstream file("C:\\Users\\ppxiao019\\OneDrive\\Desktop\\User.txt", ios::trunc);
	//ofstream file("C:\\Users\\ppxiao019\\OneDrive\\Desktop\\User.txt");/////去掉ios::app
	if(file.is_open()){
		for(auto x : u_ser) {
			file<<x.Rusermessage()<<endl;
		}
	//	file<<(u_ser.end()-1)->Rusermessage()<<endl;
		cout<<"文件写入完毕"<<endl;
		file.close();
	}
}
//////////////////////////////////
void getusernumber(){
	ifstream file("C:\\Users\\ppxiao019\\OneDrive\\Desktop\\getusernumber.txt");
	if(file.is_open()){
		string s;
		if(getline(file, s))
		{
		//	getline(file,s);
			user_number=stoi(s);
		}
		else cout<<"目前没有用户"<<endl;
	}
	cout<<"文件读取完毕"<<endl;
	file.close();
}
void updateusernumber(){
	ofstream file("C:\\Users\\ppxiao019\\OneDrive\\Desktop\\getusernumber.txt");
	if(file.is_open()){
		file<<user_number;
		cout<<endl;
	}
	cout<<"文件写入完毕"<<endl;
	file.close();
}

void getbooknumber(){
	ifstream file("C:\\Users\\ppxiao019\\OneDrive\\Desktop\\getbooknumber.txt");
	if(file.is_open()){
		string s;
		if(getline(file,s))
		{
		//	getline(file,s);
			book_number=stoi(s);
		}
		else cout<<"目前没有书本"<<endl;
	}
	cout<<"文件读取完毕"<<endl;
	file.close();
}
void updatebooknumber(){
	ofstream file("C:\\Users\\ppxiao019\\OneDrive\\Desktop\\getbooknumber.txt");////////////////////这里不用追加，直接覆盖
	if(file.is_open()){
		file<<book_number;
		cout<<endl;
	}
	cout<<"文件写入完毕"<<endl;
	file.close();
}
////////////////////////////////////
void readfilebook() {
	ifstream file("C:\\Users\\ppxiao019\\OneDrive\\Desktop\\Book.txt");
	if(file.is_open()){
		string line;
		while (getline(file, line)) {  // 逐行读取文件
			stringstream ss(line);
			string ISBN, name, publisher, writer, price_str, number_str;
			double price;
			int number;
			// 按 '-' 分割每一行的数据
			getline(ss, ISBN, '-');
			getline(ss, name, '-');
			getline(ss, publisher, '-');
			getline(ss, writer, '-');
			getline(ss, price_str, '-');
			getline(ss, number_str, '-');

			// 转换价格和数量
			price = stod(price_str);  // 将字符串转换为 double
			number = stoi(number_str);  // 将字符串转换为 int

			// 创建一个新的 Start_Book 对象并填充数据
			Start_Book book;
			book.SetISBN(ISBN);
			book.Setname(name);
			book.Setpublisher(publisher);
			book.Setwriter(writer);
			book.Setprice(price);
			book.Setnumber(number);

			// 将新的图书对象加入到 b_ook 容器中
			b_ook.push_back(book);
			book_number++;  // 增加图书数量

			newpbk.push_back(name);

		//	if(find(Shudan[name].begin(),Shudan[name].end(), name )==Shudan[name].end()) Shudan[name].push_back(name);//没找到这本书就加上这个作者的书
			if(find(Allbook[writer].begin(),Allbook[writer].end(), name )==Allbook[writer].end()) Allbook[writer].push_back(name);//该作者没找到这本书就加上这个作者的书
			sort(Allbook[writer].begin(),Allbook[writer].end());//然后排序
		}
		cout<<"文件读取完毕"<<endl;
		file.close();
	}
	//else cout<<"目前没有书本"<<endl;
}
void jieshuupdatefilebook() {
	ofstream file("C:\\Users\\ppxiao019\\OneDrive\\Desktop\\jieyuepaiming.txt", ios::trunc);
	if(file.is_open()){
		for(auto x : Paiming) {
			file<<x.first<<"-"<<x.second<<"-"<<endl;
		}
		cout<<"文件写入完毕"<<endl;
		file.close();
	}
}
void jieshureadfilebook() {
	ifstream file("C:\\Users\\ppxiao019\\OneDrive\\Desktop\\jieyuepaiming.txt");
	if(file.is_open()) {
		string name;
		while (getline(file, name)) {
			stringstream ss(name);
			string name1,number1;
			getline(ss, name1, '-');
			getline(ss, number1, '-');
			int thenumber1 = stoi(number1);
            Paiming[name1]+=thenumber1;
		}
	}
}
void Theupdatefilebook() {
	ofstream file("C:\\Users\\ppxiao019\\OneDrive\\Desktop\\Book.txt", ios::trunc);
	if(file.is_open()){
		for(auto x : b_ook) {
			file<<x.Rbookmessage()<<endl;
		}
		cout<<"文件写入完毕"<<endl;
		file.close();
	}
}
void updatefilebook(){//等价于加入书
	cout<<"您好，接下来请您输入书的信息"<<endl;
	string ISBN1,name1,publisher1,writer1;
	double price1;
	int number1;
	cout<<"请输入ISBN码：";
	cin>>ISBN1;
	cout<<endl;

	cout<<"请输入书名：";
	cin>>name1;
	cout<<endl;

	cout<<"请输入出版社的名字：";
	cin>>publisher1;
	cout<<endl;

	cout<<"请输入作者的名字：";
	cin>>writer1;
	cout<<endl;

	cout<<"请输入该书的价格：";
	cin>>price1;
	cout<<endl;

	cout<<"请输入书本的数量";
	cin>>number1;
	cout<<endl;
    newpbk.push_back(name1);
	Start_Book now={ISBN1,name1,publisher1,writer1,price1,number1};
	b_ook.push_back(now);//放书
	book_number+=number1;
	updatebooknumber();//living update
	if(find(Allbook[writer1].begin(),Allbook[writer1].end(), name1 )==Allbook[writer1].end()) Allbook[writer1].push_back(name1);//没找到这本书就加上这个作者的书
	sort(Allbook[writer1].begin(),Allbook[writer1].end());//然后排序
/*
	ofstream file("C:\\Users\\ppxiao019\\OneDrive\\Desktop\\Book.txt");/////去掉ios::app
	if(file.is_open()){
		for(auto x : b_ook) {
			file<<x.Rbookmessage()<<endl;
		}
	//	file<<(b_ook.end()-1)->Rbookmessage()<<endl;
		cout<<"文件写入完毕"<<endl;
    	file.close();
	}*/
	Theupdatefilebook();
}



////////////////////////////
void Signup(){
	string name1;
	cout<<"请输入用户名：";
	cin>>name1;
	cout<<endl;
	while(true){
	string password1,check;
    cout<<"请输入密码：";
	cin>>password1;
	cout<<endl;
	cout<<"请再输入一次密码：";
	cin>>check;
	cout<<endl;
	if(check==password1){
	User newuser={name1,password1};
	u_ser.push_back(newuser);
	user_number++;
	updatefileuser();
	updateusernumber();
	cout<<"注册成功！"<<endl;
	break;
    }
    else cout<<"密码错误，请重试！"<<endl;
    }
}
/*void recommend(string &name) {
	// 检查当前用户是否在书单中
	if (Shudan.find(name) == Shudan.end()) {
	//	cout << "用户：" << name << "不存在于该书单" << endl;
		return;
	}
	// 获取当前用户的书单
	vector<string> current_books = Shudan[name];

	// 遍历所有用户的书单，找出与当前用户相同的书单
	for (const auto& entry : Shudan) {
		// 跳过当前用户自身
		if (entry.first == name) continue;
		// 比较当前用户的书单与其他用户的书单是否相同
		if (entry.second == current_books) {
			cout<<"您可能还想借阅以下书籍"<<endl;
			for(auto &i : entry.second){
				cout<<i<<endl;
			}
		}
	}
}*/
bool check(string name) {
	for(auto &i : u_ser) {
		if(i.Rusername()==name) {
			return true;
		}
	}
	return false;
}
void jieshu(string &namee){//借书
	if(b_ook.size()==0){
		cout<<"书库为空！"<<endl;
		return;
	}
	cout<<"请输入书名："<<endl;
    string shuming;
	cin>>shuming;
	//string namee;
	bool ok=false;
	bool f=false;
	for(auto &i : b_ook){
		if(i.Rname()==shuming){
			if(i.Rnumber()>=1){
				cout<<"已找到该书，请输入您的账号，我们将登记信息！"<<endl;
				cout<<"请输入账号："<<endl;
				cin>>namee;
				if(check(namee)==false) {
					cout<<"无该用户！"<<endl;
					return;
				}
				i.number--;
				//if(find(Shudan[namee].begin(),Shudan[namee].end(), namee )==Shudan[namee].end()) Shudan[namee].push_back(namee);//没找到这本书就加上这个作者的书
				cout<<"借阅成功！请按时归还。"<<endl;
				ok=true;
				book_number--;
				updatebooknumber();
				Paiming[shuming]++;
				jieshuupdatefilebook();
				//recommend(namee);
		        return;
			}//由于没有把相同的书叠在一起，所以你爹要一直查到底，叠起来还要扫一遍，复杂度太高
			else{
				f=true;//有这本书，但是借出去了
			}
		}
	}
	if(!ok) {
		if(f)cout<<"此书已被借出"<<endl;
		else cout<<"不存在此书"<<endl;
	}
}

void findbook(){
	cout<<"通过题名查找书本请按1"<<endl;
	cout<<"通过ISBN码查找书本请按2"<<endl;
	cout<<"通过作者查找书本请按3"<<endl;
	int n;
	cin>>n;
	string s1,s2,s3;
	bool f=false;
	bool ff=false;
	switch(n){
		case 1:
			cout<<"请输入书名"<<endl;
			cin>>s1;
			for(auto &i : b_ook){
				if(i.Rname()==s1){
					cout<<"存在此书"<<endl;
					f=true;
				}
			}
		    if(!f) {
			    cout<<"不存在此书"<<endl;
		    }
			break;
		case 2:
			cout<<"请输入ISBN码"<<endl;
			cin>>s2;
			for(auto &i : b_ook){
				if(i.RISBN()==s2){
					ff=true;
					cout<<"此书存在"<<endl;
					break;
				}
			}
		    if(!ff) {
			    cout<<"此书不存在"<<endl;
		    }
			break;
		case 3://升序排书，先暴力再优化
		    cout<<"请输入作者的名字"<<endl;
            cin>>s3;
            cout<<"这位作者的书有："<<endl;
            for(string& st : Allbook[s3]){
            	cout<<"-"<<st<<endl;
			}
			break;
		default:break;
	}
	cout<<"按任意键退出"<<endl;
}

class Admin{
	public:
		string adminusername;
		string adminuserpassword;
		Admin(string a,string b) : adminusername(a),adminuserpassword(b){}

        bool authenticate(const string& username, const string& password) {
        return (username == adminusername && password == adminuserpassword);
        }

        void chongzhimima(vector<User> &u_ser) {
		cout<<"请输入该用户的账号"<<endl;
		string name;
		cin>>name;
		bool ok=false;
		for(auto &i : u_ser) {
			if(i.username==name) {
				i.Setuserpassword("123456");
				ok=true;
				cout << "读者密码已被重置为123456" << endl;
			//	ofstream truncateFile("C:\\Users\\ppxiao019\\OneDrive\\Desktop\\User.txt", ios::trunc);
				updatefileuser();
				break;
		    	}
	    	}
		if(!ok)cout<<"不存在该用户"<<endl;
        }

        void userzeng(vector<User> &u_ser){
        	Signup();
		}
		void usershan(vector<User> &u_ser){
			string name;
			cout<<"请输入您想要删除的账户的账号"<<endl;
			cin>>name;
            for(auto i=u_ser.begin();i!=u_ser.end();++i){
            	if(i->Rusername()==name){
            		u_ser.erase(i);
            		cout<<"用户"<<name<<"已删除"<<endl;
            		return;
				}
			}
			cout<<"未找到改用户"<<endl;
		}
		void usergai(vector<User> &u_ser){
			string name;
			cout<<"请输入您想要修改的用户的账号：";
			cin>>name;
			cout<<endl;
			int temp=0;
			bool f=false;
			for(int i=0;i<u_ser.size();i++){
				if(u_ser[i].Rusername()==name){
					temp=i;////////////////
					f=true;
					break;
				}
			}
			if(!f){
				cout<<"用户不存在"<<endl;
				return;
			}
			int gg;
			cin>>gg;
			string newname,newpassword;
			cout<<"修改用户的用户名请按1"<<endl;
			cout<<"修改用户的密码请按2"<<endl;
			cout<<"修改用户的账号和密码请按3"<<endl;
			switch(gg){
				case 1:
					cout<<"请输入新的账号：";
					cin>>newname;
					cout<<endl;
					u_ser[temp].Setusername(newname);
				  //  updatefileuser();
					break;
				case 2:
					cout<<"请输入新的密码：";
					cin>>newpassword;
					cout<<endl;
					u_ser[temp].Setuserpassword(newpassword);
				 //   updatefileuser();
					break;
				case 3:
					cout<<"请输入新的账号：";
					cin>>newname;
					cout<<endl;
					cout<<"请输入新的密码：";
					cin>>newpassword;
					cout<<endl;
					u_ser[temp].Setusername(newname);
					u_ser[temp].Setuserpassword(newpassword);
				//    updatefileuser();
					break;
				default : cout<<"输入错误，请重新输入！"<<endl;
			}
			updatefileuser();
			cout<<"请按空格退出"<<endl;
		}
		void usercha(vector<User> &u_ser){
			string name;
			cout<<"请输入您想要查找的用户的账号：";
			cin>>name;
			cout<<endl;
			int temp=0;
			bool f=false;
			for(int i=0;i<u_ser.size();i++){
				if(u_ser[i].Rusername()==name){
					temp=i;////////////
					f=true;
					break;
				}
			}
			if(!f){
				cout<<"用户不存在"<<endl;
				return;
			}
			else{
				cout<<"用户已找到"<<endl;
				cout<<"该用户的用户名为："<<name<<endl;
				cout<<"该用户的密码为："<<u_ser[temp].Ruserpassword()<<endl;
			}
		}
		void bookzeng(){
			updatefilebook();
		}
		void bookshan(vector<Start_Book> &b_ook){
			string name;
			cout<<"请输入你要删除的书的书名：";
			cin>>name;
			cout<<endl;
			bool f=false;
			for(int i=0;i<b_ook.size();i++){
				if(b_ook[i].Rname()==name){
                b_ook.erase(b_ook.begin()+i);
                f=true;
					Theupdatefilebook();
				cout<<"该书已删除"<<endl;
				return;
				}
			}
			if(!f)cout<<"该书不存在！"<<endl;
		}
		void bookgai(vector<Start_Book> &b_ook){
			string name;
		    cout<<" 请输入你想修改的书的名字"<<endl;
		    cin>>name;
		    int temp=0;
		    bool f=false;
		    cout<<endl;
		    for(int i=0;i<b_ook.size();i++){
		    	if(b_ook[i].Rname()==name){
		    		temp=i;
		    		f=true;
		    		break;
				}
			}
			if(!f){
				cout<<"该书不存在！"<<endl;
				return;
			}
			string newname,newwriter,newpublisher,newISBN;
			double newprice;
			int newnumber;
			int gg;
			cout<<"修改书名请按1"<<endl;
			cout<<"修改书的价格请按2"<<endl;
			cout<<"修改书的出版社请按3"<<endl;
			cout<<"修改书的ISBN码请按4"<<endl;
			cout<<"修改书的作者请按5"<<endl;
			cout<<"修改书的数量请按6"<<endl;
			cin>>gg;
			switch(gg){
				case 1:
					cout<<"请输入新的书名：";
					cin>>newname;
					cout<<endl;
					b_ook[temp].Setname(newname);
					break;
				case 2:
					cout<<"请输入新的价格：";
					cin>>newprice;
					cout<<endl;
					b_ook[temp].Setprice(newprice);
					break;
				case 3:
					cout<<"请输入新的出版社：";
					cin>>newpublisher;
					cout<<endl;
					b_ook[temp].Setpublisher(newpublisher);
					break;
				case 4:
					cout<<"请输入新的ISBN码：";
					cin>>newISBN;
					cout<<endl;
					b_ook[temp].SetISBN(newISBN);
					break;
				case 5:
					cout<<"请输入新的作者：";
					cin>>newwriter;
					cout<<endl;
					b_ook[temp].Setwriter(newwriter);
					break;
				case 6:
					cout<<"请输入新的数量：";
					cin>>newnumber;
					cout<<endl;
					b_ook[temp].Setnumber(newnumber);
					break;
				default : cout<<"输入错误，请重新输入！";
			}
			Theupdatefilebook();
		}
		void bookcha(){
			findbook();
		}
	    void clearfile() {
			ofstream truncateFile("C:\\Users\\ppxiao019\\OneDrive\\Desktop\\User.txt", ios::trunc);
			ofstream truncateFile1("C:\\Users\\ppxiao019\\OneDrive\\Desktop\\getusernumber.txt", ios::trunc);
			ofstream truncateFile2("C:\\Users\\ppxiao019\\OneDrive\\Desktop\\getbooknumber.txt", ios::trunc);
			ofstream truncateFile3("C:\\Users\\ppxiao019\\OneDrive\\Desktop\\Book.txt", ios::trunc);
			cout<<"清除成功！请重新登录以刷新。"<<endl;
		}

};
void Login(){
	bool ok=false;
	string name,password;
	cout<<"请输入账号："<<endl;
	cin>>name;
	cout<<"请输入密码："<<endl;
	cin>>password;
    for(auto &x : u_ser) {
	    if(x.username==name) {
		    ok=true;
	    	break;
	    }
    }
	if(!ok) {
		cout<<"用户不存在！"<<endl;
		return;
	}
	for(auto &i : u_ser) {
		if(name==i.Rusername()){
			if(i.userpassword==password)cout<<"登录成功！"<<endl;
			else {
				cout<<"密码错误！请重新登录。"<<endl;
				return;
			}
		}
	}
	int x;
	cout<<"借阅图书请按1"<<endl;
	cout<<"归还书籍请按2"<<endl;
	cin>>x;
	if(x==1) {
		jieshu(name);
	}
	else if(x==2) {
		updatefilebook();
	}
}
void jiemian(){//界面
	cout<<"|--------------|"<<endl;
	cout<<"|  图书管理系统  |"<<endl;
	cout<<"|   1：登录     |"<<endl;
	cout<<"|   2：注册     |"<<endl;
	cout<<"|  3.回到主界面  |"<<endl;
	cout<<"|--------------|"<<endl;
    int ans;
    cin>>ans;
	switch(ans){
		case 1:
			Login();
			break;
		case 2:
			Signup();
			break;
		case 3:
			break;
		default:
			cout<<"无效按键"<<endl;
			cout<<"请按空格退出界面"<<endl;
			return;
	}
}
void UserPage(){
	cout<<"|---------------|"<<endl;
	cout<<"|1.【浏览图书】   |"<<endl;
	cout<<"|2.【Hi!2025】   |"<<endl;
	cout<<"|3.【归还图书】   |"<<endl;
	cout<<"|4.【查找图书】   |"<<endl;
	cout<<"|5.【借阅排名】   |"<<endl;
	cout<<"|6.【出版排名】   |"<<endl;
	cout<<"|7.【返回上级】   |"<<endl;
	cout<<"|退 出 请 按 0!  |"<<endl;
	cout<<"|---------------|"<<endl;
}
void showbook() {
	for(auto &i : b_ook) {
		cout<<"书名："<<i.name<<"  "<<"作者："<<i.writer<<endl;;
	}
}
void showuser() {
	for(auto i : u_ser) {
		cout<<i.username<<endl;
	}
}
void newpublishbook() {//最新出版前十的书
	if(newpbk.size()==0) {
		cout<<"目前暂无图书"<<endl;
		return;
	}
	int cnt=1;
	for(auto i=newpbk.rbegin();i!=newpbk.rend();++i){
		cout<<cnt<<"："<<*i<<endl;
		cnt++;
		if(cnt>=10)break;
	}
}
void paihangbang(){
	vector<pair<string, int>> vec(Paiming.begin(), Paiming.end());

	// 使用自定义的排序规则（按值排序）
	sort(vec.begin(), vec.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
		return a.second > b.second;  // 按值降序排序
	});

	// 输出排序后的结果
	int ans=1;
	if(vec.size()==0) {
		cout<<"目前暂无排名"<<endl;
		return;
	}
	for (const auto& p : vec) {
		cout << ans<<"："<<p.first << " " << p.second << endl;
		ans++;
		if(ans>10)return;
	}
}

int main(){
	//ofstream truncateFile("C:\\Users\\ppxiao019\\OneDrive\\Desktop\\User.txt", ios::trunc);
	//ofstream truncateFile1("C:\\Users\\ppxiao019\\OneDrive\\Desktop\\getusernumber.txt", ios::trunc);
	//ofstream truncateFile2("C:\\Users\\ppxiao019\\OneDrive\\Desktop\\getbooknumber.txt", ios::trunc);
	//ofstream truncateFile3("C:\\Users\\ppxiao019\\OneDrive\\Desktop\\Book.txt", ios::trunc);
	readfilebook();
	readfileuser();
	getusernumber();
	getbooknumber();
	jieshureadfilebook();
//	for(auto x : u_ser)cout<<x.username<<"  "<<x.userpassword<<endl;
	Admin admin("admin","123456");
	while(true) {
		cout<<"注册或登录请按1"<<endl;
		cout<<"进入图书管理请按2"<<endl;
		cout<<"管理员登录请按3"<<endl;
		cout<<"退出请按4"<<endl;
		int start;
		cin>>start;
		if(start==1) {
			jiemian();
		}
		else if(start==2) {
			UserPage();
			int x;
			cin>>x;
			if(x==0)break;
			if(x==1)showbook();
			if(x==2)cout<<"新年快乐"<<endl;
			if(x==3)updatefilebook();
			if(x==4)findbook();
			if(x==5)paihangbang();
			if(x==6)newpublishbook();
			if(x==7)cout<<"已为您返回上一个界面"<<endl;
		}
		else if(start==3) {
			string name,password;
			cout<<"请输入账号"<<endl;
			cin>>name;
			cout<<"请输入密码"<<endl;
			cin>>password;
			if(admin.authenticate(name,password)) {
				cout<<"欢迎您，管理员。"<<endl;
				int x;
				cout<<"增加用户请按1"<<endl;
				cout<<"删除用户请按2"<<endl;
				cout<<"修改用户请按3"<<endl;
				cout<<"查找用户请按4"<<endl;
				cout<<"增加书本请按5"<<endl;
				cout<<"删除书本请按6"<<endl;
				cout<<"修改书本请按7"<<endl;
				cout<<"查找书本请按8"<<endl;
				cout<<"重置用户密码请按9"<<endl;
				cout<<"清除全部信息请按10"<<endl;
				cout<<"返回上一个界面请按11"<<endl;
				cin>>x;
				if(x==1)admin.userzeng(u_ser);
				if(x==2)admin.usershan(u_ser);
				if(x==3)admin.usergai(u_ser);
				if(x==4)admin.usercha(u_ser);
				if(x==5)admin.bookzeng();
				if(x==6)admin.bookshan(b_ook);
				if(x==7)admin.bookgai(b_ook);
				if(x==8)admin.bookcha();
				if(x==9)admin.chongzhimima(u_ser);
				if(x==10)admin.clearfile();
				if(x==11)cout<<"已返回上一个界面"<<endl;
			}
			else cout<<"您不是管理员"<<endl;
		}
		else if(start==4)break;
		else cout<<"请按指示正确输入"<<endl;
	}
	return 0;
}