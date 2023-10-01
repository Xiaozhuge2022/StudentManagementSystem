#include<iostream> 
#include<iomanip> 
#include<cstring>
#include<algorithm>
#include<fstream> 
#include<cmath>
using namespace std;
#define  FILENAME "stuFile.txt"//文件路径添加为宏常量


//创建课程course基类 
class course {
public:
	course() {
		m_course_id = -1;
		m_course_grade = -1;
		m_course_credit = 2;///默认两学分 仍可输入更改 

	}
	int m_course_id;//
	int  m_course_grade;//课程成绩 
	int m_course_credit;//课程学分 

};


//创建cucer学生基类 
class CUCer {
public:
	virtual void showInfo() = 0;//显示个人信息
	virtual string getXueYuan() = 0;// 显示学院 
	string m_name;
	long long  m_id;
	int m_XueYuanid;//学生所在学院id 
	string m_class;//班级 
	int sum_score;//总分 
	double GPA;
	course course_array[20];//每位学生有多门课  借助桶排序 的思想 课程数组下标就是课程 id 
};


//创建信通（XT）学生类 继承cucer学生基类。
class XT_student : public CUCer {
public:
	//friend class  StudentScoreMangeger;
	virtual void showInfo();
	virtual string getXueYuan();
	XT_student(string tempclass, string name, long long id, int s1, int c1, int s2, int c2, int s3, int c3, int s4, int c4, int XueYuanid);

};
XT_student::XT_student(string tempclass, string name, long long id, int s1, int c1, int s2, int c2, int s3, int c3, int s4, int c4, int XueYuanid) {
	this->m_class = tempclass;
	this->m_name = name;
	this->m_id = id;
	this->m_XueYuanid = XueYuanid;
	//将课程序号 成绩 学分初始化 
	this->course_array[1].m_course_id = 1; 
	this->course_array[1].m_course_grade = s1; 
	this->course_array[1].m_course_credit = c1;
	
	this->course_array[2].m_course_id = 2; 
	this->course_array[2].m_course_grade = s2; 
	this->course_array[2].m_course_credit = c2;

	this->course_array[3].m_course_id = 3; 
	this->course_array[3].m_course_grade = s3; 
	this->course_array[3].m_course_credit = c3;

	this->course_array[4].m_course_id = 4; 
	this->course_array[4].m_course_grade = s4; 
	this->course_array[4].m_course_credit = c4;

	sum_score = s1 + s2 + s3 + s4;
	if (c1 + c2 + c3 + c4 != 0)//计算GPA 
		GPA = 1.0*(s1 * c1 + s2 * c2 + s3 * c3 + s4 * c4) / ((c1 + c2 + c3 + c4)*20);
}


//创建计网（JW）学生类 继承cucer学生基类。 	
class JW_student : public CUCer {
public:
	friend class  StudentScoreMangeger;
	virtual void showInfo();  //多态展示信息函数 
	virtual string getXueYuan();
	JW_student(string tempclass, string name, long long id, int s1, int c1, int s2, int c2, int s3, int c3, int s4, int c4, int XueYuanid);

};
JW_student::JW_student(string tempclass, string name, long long id, int s1, int c1, int s2, int c2, int s3, int c3, int s4, int c4, int XueYuanid) {
	this->m_class = tempclass;
	this->m_name = name;
	this->m_id = id;
	this->m_XueYuanid = XueYuanid;
	//将课程序号 成绩 学分初始化 
	this->course_array[1].m_course_id = 1; 
	this->course_array[1].m_course_grade = s1; 
	this->course_array[1].m_course_credit = c1;

	this->course_array[5].m_course_id = 5; 
	this->course_array[5].m_course_grade = s2; 
	this->course_array[5].m_course_credit = c2;

	this->course_array[6].m_course_id = 6; 
	this->course_array[6].m_course_grade = s3; 
	this->course_array[6].m_course_credit = c3;

	this->course_array[7].m_course_id = 7; 
	this->course_array[7].m_course_grade = s4; 
	this->course_array[7].m_course_credit = c4;
	
	sum_score = s1 + s2 + s3 + s4;
	if (c1 + c2 + c3 + c4 != 0)
		GPA = 1.0*(s1 * c1 + s2 * c2 + s3 * c3 + s4 * c4) / ((c1 + c2 + c3 + c4)*20);//千万注意 
}


//创建学生成绩管理系统类
class  StudentScoreMangeger {

public:
	//构造函数 
	StudentScoreMangeger();

	//录入学生信息 
	void Add_Stu();

	//保存文件 
	void save();

	//初始化学生 
	void init_Stu();

	//统计人数
	int get_StuNum();

	//浏览所有学生信息
	void Show_Stu();

	//推出程序 
	void exitSystem();

	//展示菜单 
	void Show_Menu_tea();
	void Show_Menu_stu(); 

	//删除学生信息 
	void Del_Stu();

	//清空文件
	void Clean_File();

	//学生排序 
	void Sort_Stu();

	//查找学生 
	void Find_Stu();

	//修改学生 
	void Mod_Stu();

	//按照学生编号判断是否存在,若存在返回在数组中位置，不存在返回-1
	int IsExist(long long id);

	~StudentScoreMangeger() {
		if (this->m_StuArray != NULL)
		{
			delete[] this->m_StuArray;
		}
	}
	bool m_FileIsEmpty;////标志文件是否为空
	int m_StuNum;//记录文学生人数 
	CUCer** m_StuArray;// 学生数组的指针
};

//学生成绩管理系统类 默认构造函数 
StudentScoreMangeger::StudentScoreMangeger() {

	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	//文件不存在情况
	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl; //测试输出
		this->m_StuNum = 0;  //初始化人数
		this->m_FileIsEmpty = true; //初始化文件为空标志
		this->m_StuArray = NULL; //初始化数组
		ifs.close(); //关闭文件
		return;
	}

	//文件存在，并且没有记录
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空!" << endl;
		this->m_StuNum = 0;
		this->m_FileIsEmpty = true;
		this->m_StuArray = NULL;
		ifs.close();
		return;
	}
	int num = this->get_StuNum();
	//cout << "学生个数为：" << num << endl;  //测试代码
	this->m_StuNum = num;  //更新成员属性 

	//根据学生数创建数组
	this->m_StuArray = new CUCer * [this->m_StuNum];
	//初始化职工
	init_Stu();

}

//保存文件
void StudentScoreMangeger::save() {

	ofstream ofs;
	ofs.open(FILENAME, ios::out);


	for (int i = 0; i < this->m_StuNum; i++)
	{
		if(m_StuArray[i] ->m_XueYuanid ==1)  //信通学院 
			ofs << this->m_StuArray[i]->m_XueYuanid << " "
				<< this->m_StuArray[i]->m_class << " "
				<< this->m_StuArray[i]->m_name << " "
				<< this->m_StuArray[i]->m_id << " "

				<< this->m_StuArray[i]->course_array[1].m_course_grade << " "
				<< this->m_StuArray[i]->course_array[2].m_course_grade << " "
				<< this->m_StuArray[i]->course_array[3].m_course_grade << " "
				<< this->m_StuArray[i]->course_array[4].m_course_grade << endl;
		else {//计网学院 
			ofs << this->m_StuArray[i]->m_XueYuanid << " "
				<< this->m_StuArray[i]->m_class << " "
				<< this->m_StuArray[i]->m_name << " "
				<< this->m_StuArray[i]->m_id << " "

				<< this->m_StuArray[i]->course_array[1].m_course_grade << " "
				<< this->m_StuArray[i]->course_array[5].m_course_grade << " "
				<< this->m_StuArray[i]->course_array[6].m_course_grade << " "
				<< this->m_StuArray[i]->course_array[7].m_course_grade << endl;


		}



	}

	ofs.close();

}

//显示菜单 教师端页面 
void StudentScoreMangeger::Show_Menu_tea() {

	cout << "********************************************" << endl;
	cout << "******  欢迎使用CUC学生成绩管理系统！ ******" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.录入学生成绩  *************" << endl;
	cout << "*************  2.删除学生成绩  *************" << endl;
	cout << "*************  3.修改学生信息  *************" << endl;
	cout << "*************  4.浏览学生成绩  *************" << endl;
	cout << "*************  5.查找学生成绩  *************" << endl;
	cout << "*************  6.统计成绩排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}


//显示菜单 学生端页面 
void StudentScoreMangeger::Show_Menu_stu() {

	cout << "********************************************" << endl;
	cout << "******  欢迎使用CUC学生成绩管理系统！ ******" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  4.浏览学生成绩  *************" << endl;
	cout << "*************  5.查找学生成绩  *************" << endl;
	cout << "*************  6.统计成绩排序  *************" << endl;
	cout << "*************(其他功能暂无权限)**************" << endl;
	cout << endl;
}
//录入学生信息 
void StudentScoreMangeger::Add_Stu() {
	cout << "请输入增加学生数量： " ;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		//计算新空间大小
		int newSize = this->m_StuNum + addNum;

		//开辟新空间
		CUCer** newSpace = new CUCer * [newSize];

		//将原空间下内容存放到新空间下
		if (this->m_StuArray != NULL)
		{
			for (int i = 0; i < this->m_StuNum; i++)
			{
				newSpace[i] = this->m_StuArray[i];
			}
		}

		//输入新数据
		for (int i = 0; i < addNum; i++)
		{
			string tempclass;
			string name;
			long long  id;
			int dSelect;
			int s1, c1, s2, c2, s3, c3, s4, c4;
            //按照提示输入相关信息 
			cout << "请输入第 " << i + 1 << " 个新学生班级：" <<endl;
			cin >> tempclass;
			cout << "请输入第 " << i + 1 << " 个新学生姓名：" <<endl;
			cin >> name;
			cout << "请输入第 " << i + 1 << " 个新学生学号(13位)：" <<endl;
			cin >> id;

			cout << "请输入第 " << i + 1 << " 个新学生4门课及学分：" <<
			" (例如 ：成绩1 学分1 成绩2 学分2......)" <<endl;
			
			cin >> s1;
			cin >> c1;
			cin >> s2;
			cin >> c2;
			cin >> s3;
			cin >> c3;
			cin >> s4;
			cin >> c4;
            cout << "请输入该生的学院：" << endl;
		
			cout << "1.信息与通信工程学院  " << endl;
			cout << "2.计算机与网络安全学院  " << endl;
			
			cin >> dSelect;

			CUCer* cucer = NULL;
			switch (dSelect)
			{
			case 1: //信通 
				cucer = new XT_student(tempclass, name, id, s1, c1, s2, c2, s3, c3, s4, c4, 1);
				break;
			case 2: //计网 
				cucer = new JW_student(tempclass, name, id, s1, c1, s2, c2, s3, c3, s4, c4, 2);
				break;
			default:
				break;
			}
			newSpace[this->m_StuNum + i] = cucer;
		}

		//释放原有空间
		delete[] this->m_StuArray;

		//更改新空间的指向
		this->m_StuArray = newSpace;

		//更新新的个数
		this->m_StuNum = newSize;

		//更新职工不为空标志
		this->m_FileIsEmpty = false;

		//提示信息
		cout << "成功添加" << addNum << "名新学生成绩！" << endl;

		//保存到文件
		this->save();
	}
	else
	{
		cout << "输入有误" << endl;
	}

	system("pause");
	system("cls");
}

//获取记录的学生人数
int StudentScoreMangeger::get_StuNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);


	string tclass;
	string name;
	long long  id;
	int s1, s2,  s3,  s4;
	int Xueyuanid;

	int num = 0;

	while (ifs >> Xueyuanid && ifs >> tclass && ifs >> name && ifs >> id && ifs >> s1 && ifs >> s2 && ifs >> s3 && ifs >> s4)
	{
		//记录人数
		num++;
	}
	ifs.close();

	return num;
}

//初始化数组 
void StudentScoreMangeger::init_Stu() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	string tclass;
	string name;
	long long  id;
	int s11 = 0, c11 = 2, s22 = 0, c22 = 2, s33 = 0, c33 = 2, s44 = 0, c44 = 2;
	int Xueyuanid;

	int index = 0;
	while (ifs >> Xueyuanid && ifs >> tclass && ifs >> name && ifs >> id && ifs >> s11 && ifs >> s22 && ifs >> s33 && ifs >> s44)
	{
		CUCer* cucer = NULL;
		//根据不同的学院Id创建不同对象
		if (Xueyuanid == 1)  // 1信通
		{
			cucer = new XT_student(tclass, name, id, s11, 4, s22, 6, s33, 5, s44, 3, 1);
		}
		else  //2计网 
		{
			cucer = new JW_student(tclass, name, id, s11, 4, s22, 5, s33, 4, s44, 3, 2);
		}

		//存放在数组中
		this->m_StuArray[index] = cucer;
		index++;
	}
}

//判断学生是否存在 
int StudentScoreMangeger::IsExist(long long  id) {
	int index = -1;

	for (int i = 0; i < this->m_StuNum; i++)
	{
		if (this->m_StuArray[i]->m_id == id)
		{
			index = i;

			break;
		}
	}

	return index;
}

//显示所有学生信息 
void StudentScoreMangeger::Show_Stu() {
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < m_StuNum; i++)
		{
			//利用多态调用接口
			this->m_StuArray[i]->showInfo();
		}
		cout<<"共录入"<< StudentScoreMangeger::m_StuNum <<"名学生"<<endl;
	}

	system("pause");
	system("cls");
}

//删除学生信息 
void StudentScoreMangeger::Del_Stu() {
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		//按学生学号删除
		cout << "请输入想要删除的学号：" << endl;
		long long  id = 0;
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1)  //说明index上位置数据需要删除
		{
			for (int i = index; i < this->m_StuNum - 1; i++)
			{
				this->m_StuArray[i] = this->m_StuArray[i + 1];//采用覆盖删除的方法 
			}
			this->m_StuNum--;

			this->save(); //删除后数据同步到文件中
			cout << "删除成功！" << endl;
		}
		else
		{
			cout << "删除失败，未找到该学生" << endl;
		}
	}

	system("pause");
	system("cls");

}

//清空文件
void StudentScoreMangeger::Clean_File() {
	cout << "********************************************"<<endl;
	cout << "****            1、确认               ******" << endl;
	cout << "****            2、返回               ******" << endl;
	cout << "********************************************"<<endl;
	
	cout << "确认清空？" << endl;
	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//打开模式 ios::trunc 如果存在删除文件并重新创建
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_StuArray != NULL)
		{
			for (int i = 0; i < this->m_StuNum; i++)
			{
				if (this->m_StuArray[i] != NULL)
				{
					delete this->m_StuArray[i];
				}
			}
			this->m_StuNum = 0;
			delete[] this->m_StuArray;
			this->m_StuArray = NULL;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功！" << endl;
	}

	system("pause");
	system("cls");
}


//统计学生成绩 和 学生排序 
void StudentScoreMangeger::Sort_Stu() {
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
		system("pause");
		system("cls");
	}
	else
	{	//统计学生成绩，按照**班级和科目计算平均分**。  500  
		cout<<"********************************************"<<endl;
		cout<<"****1.学院内按所有课程总分排序        ******"<<endl;
		cout<<"****2.学院内按平均学分绩点（GPA）排序 ******" << endl;
		cout<<"****3.班级内按照所有课程总分排序      ******" << endl; 
		cout<<"****4.班级内按平均学分绩点（GPA）排序 ******" << endl;
		cout<<"****5.某一门课程成绩排序              ******" << endl;  
		cout<<"********************************************"<<endl;
		cout<<"请选择排序方式： " << endl;
		string choice_class;//记录选择查询的班级
		int choice;//记录查询的方式12345
		cin >> choice;
		int k = 0;
		double sum_score_sort = 0;//记录查询总分  用于计算平均分
		switch (choice) {
		case 1:

			//由于是二级指针 不会使用sort排序 只能使用简单的冒泡 排序 
			//sort(m_StuArray,(m_StuArray+m_StuNum));

			for (int i = 0; i < m_StuNum - 1; i++) {
				for (int j = 0; j < m_StuNum - i - 1; j++) {
					if (m_StuArray[j]->sum_score < m_StuArray[j + 1]->sum_score) {
						CUCer* temp = m_StuArray[j];
						m_StuArray[j] = m_StuArray[j + 1];
						m_StuArray[j + 1] = temp;
					}
				}
			}

			cout << "********************************************"<<endl;
			cout << "****        1.信息与通信工程学院      ******" << endl;
			cout << "****        2.计算机与网络安全学院    ******" << endl;
			cout << "********************************************"<<endl;
			cout << "请输入你要查询的学院：" << endl;
			int choice_xueyuan;
			cin >> choice_xueyuan;//记录查询的学院 

			if (choice_xueyuan == 1) {
				cout << "信息与通信工程学院所有学生课程总分排序如下：" << endl;
				for (int i = 0; i < m_StuNum; i++) {
					if (m_StuArray[i]->m_XueYuanid == 1) {//“1”表示是信通人 
						k++;
						cout << "第" << k << "名" 
							<< '\t'<<"班级:" << m_StuArray[i]->m_class
							<< '\t'<<"姓名:" << m_StuArray[i]->m_name
							<< '\t'<<"学号:" << m_StuArray[i]->m_id
							<< '\t'<<"总分:" << m_StuArray[i]->sum_score << endl;
						sum_score_sort += m_StuArray[i]->sum_score;

					}
				}
			}
			else {
				cout << "计算机与网络安全学院所有学生课程总分排序如下：" << endl;
				for (int i = 0; i < m_StuNum; i++) {
					if (m_StuArray[i]->m_XueYuanid == 2) {//“2”表示是计网人 
						k++;
						cout << "第" << k << "名" 
							<< '\t'<<"班级： " << m_StuArray[i]->m_class
							<< '\t'<<"姓名:  " << m_StuArray[i]->m_name
							<< '\t'<<"学号： " << m_StuArray[i]->m_id
							<< '\t'<<"总分： " << m_StuArray[i]->sum_score << endl;
						sum_score_sort += m_StuArray[i]->sum_score;
					}
				}
			}

			//输出学院课程总分平均分
			cout << "**学院院课程总分平均分:**" << (double)sum_score_sort / k << endl;
			break;
		case 2:
			for (int i = 0; i < m_StuNum - 1; i++) {
				for (int j = 0; j < m_StuNum - i - 1; j++) {
					if (m_StuArray[j]->GPA < m_StuArray[j + 1]->GPA) {
						CUCer* temp = m_StuArray[j];
						m_StuArray[j] = m_StuArray[j + 1];
						m_StuArray[j + 1] = temp;
					}
				}
			}

			cout << "********************************************"<<endl;
			cout << "****        1.信息与通信工程学院      ******" << endl;
			cout << "****        2.计算机与网络安全学院    ******" << endl;
			cout << "********************************************"<<endl;
			cout << "请输入你要查询的学院：" << endl;
			
			int choice_xueyuan01;

			cin >> choice_xueyuan01;
			if (choice_xueyuan01 == 1) {
				cout << "信息与通信工程学院所有学生GPA排序如下：" << endl;
				for (int i = 0; i < m_StuNum; i++) {
					if (m_StuArray[i]->m_XueYuanid == 1) {//“1”表示是信通人 
						k++;
						cout << "第" << k << "名" 
							<< '\t'<<"班级： " << m_StuArray[i]->m_class
							<< '\t'<<"姓名:  " << m_StuArray[i]->m_name
							<< '\t'<<"学号： " << m_StuArray[i]->m_id
							<< '\t'<<"总分： " << m_StuArray[i]->GPA << endl;
						sum_score_sort += m_StuArray[i]->GPA;

					}
				}
			}
			else {
				cout << "计算机与网络安全学院所有学生GPA排序如下：" << endl;
				for (int i = 0; i < m_StuNum; i++) {
					if (m_StuArray[i]->m_XueYuanid == 2) {//“2”表示是计网人 
						k++;
						cout << "第" << k << "名" 
							<< '\t'<<"班级： " << m_StuArray[i]->m_class
							<< '\t'<<"姓名:  " << m_StuArray[i]->m_name
							<< '\t'<<"学号： " << m_StuArray[i]->m_id
							<< '\t'<<"总分： " << m_StuArray[i]->GPA << endl;
							sum_score_sort += m_StuArray[i]->GPA;
					}
				}
			}


			//输出学院院课程学分加权平均分
			cout << "学院院课程学分加权平均分:" << (double)sum_score_sort / k << endl;
			break;
		case 3:
			for (int i = 0; i < m_StuNum - 1; i++) {
				for (int j = 0; j < m_StuNum - i - 1; j++) {
					if (m_StuArray[j]->sum_score < m_StuArray[j + 1]->sum_score) {
						CUCer* temp = m_StuArray[j];
						m_StuArray[j] = m_StuArray[j + 1];
						m_StuArray[j + 1] = temp;
					}
				}
			}

			cout << "请输入你要查询的班级：" << endl;
			
			cin >> choice_class;//记录查询的班级

			
				cout << "该班所有学生课程总分排序如下：" << endl;
				for (int i = 0; i < m_StuNum; i++) {
					if (m_StuArray[i]->m_class  == choice_class) {//表示是这个班同学 
						k++;
						cout << "第" << k << "名" 
							<< '\t'<<"班级： " << m_StuArray[i]->m_class
							<< '\t'<<"姓名:  " << m_StuArray[i]->m_name
							<< '\t'<<"学号： " << m_StuArray[i]->m_id
							<< '\t'<<"总分： " << m_StuArray[i]->sum_score << endl;
						    sum_score_sort += m_StuArray[i]->sum_score;
					}
				}
				//输出班级课程总分平均分
				cout << "班级课程学分平均分:" << (double)sum_score_sort / k << endl;

			break;

		case 4:
			for (int i = 0; i < m_StuNum - 1; i++) {
				for (int j = 0; j < m_StuNum - i - 1; j++) {
					if (m_StuArray[j]->GPA  < m_StuArray[j + 1]->GPA) {
						CUCer* temp = m_StuArray[j];
						m_StuArray[j] = m_StuArray[j + 1];
						m_StuArray[j + 1] = temp;
					}
				}
			}

			cout << "请输入你要查询的班级：" << endl;
			
			cin >> choice_class;//记录查询的学院 


			cout << "该班所有学生课程加权平均分排序如下：" << endl;
			for (int i = 0; i < m_StuNum; i++) {
				if (m_StuArray[i]->m_class == choice_class) {//表示是这个班同学 
					k++;
					cout << "第" << k << "名"
						<< '\t'<<"班级： " << m_StuArray[i]->m_class
						<< '\t'<<"姓名:  " << m_StuArray[i]->m_name
						<< '\t'<<"学号： " << m_StuArray[i]->m_id
						<< '\t'<<"总分： " << m_StuArray[i]->GPA << endl;
					sum_score_sort += m_StuArray[i]->GPA;

				}
			}
			//输出班级课程总分加权平均分
			cout << "班级课程加权平均分:" << (double)sum_score_sort / k << endl;
			break;
		case 5:
				cout << "********************************************"<<endl;
				cout << "****             1.c/c++              ******" << endl;
				cout << "****             2.高数               ******" << endl;
				cout << "****             3.模电               ******" << endl;
				cout << "****             4.数电               ******" << endl;
				cout << "****             5.python             ******" << endl;
				cout << "****             6.java               ******" << endl;
				cout << "****             7.PHP                ******" << endl;
				cout << "********************************************"<<endl;
			cout << "请输入你要排名的课程序号：" << endl;
			int choice_class05;
			cin >> choice_class05;//记录所选的课程序号 
			 //将按照这门课成绩全排，没选课的人成绩为-1 
			for (int i = 0; i < m_StuNum - 1; i++) {
				for (int j = 0; j < m_StuNum - i - 1; j++) {
					if (m_StuArray[j]->course_array[choice_class05].m_course_grade < m_StuArray[j + 1]->course_array[choice_class05].m_course_grade) {
						CUCer* temp = m_StuArray[j];
						m_StuArray[j] = m_StuArray[j + 1];
						m_StuArray[j + 1] = temp;
					}
				}
			}
			cout << "选这门课的人按照成绩排序为：" << endl;

			for (int i = 0; i < m_StuNum; i++) {
				if (m_StuArray[i]->course_array[choice_class05].m_course_grade != -1) {//排除没选课的人 （成绩为-1 ） 
					k++;

					cout << "第" << k << "名"
						<< '\t'<<"学院： " << m_StuArray[i]->getXueYuan()
						<< '\t'<<"班级： " << m_StuArray[i]->m_class
						<< '\t'<<"姓名:  " << m_StuArray[i]->m_name
						<< '\t'<<"学号： " << m_StuArray[i]->m_id
						<< '\t'<<"成绩： " << m_StuArray[i]->course_array[choice_class05].m_course_grade << endl;
					sum_score_sort += m_StuArray[i]->course_array[choice_class05].m_course_grade;
				}
			}

			//输出班级平均分
			
			cout << "**课程平均分:**" << (double)sum_score_sort / k << endl;
			break;
		default:
			cout << "输入错误" << endl;
			break;
		}

		system("pause");
		system("cls");
	}


}

//修改学生信息 
void StudentScoreMangeger::Mod_Stu() {
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
		system("pause");
		system("cls");
	}
	else {
		//按学生学号修改 
		cout << "请输入想要修改的学号：" << endl;
		long long  id = 0;
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1) {  //说明index上位置数据需要修改 
			cout << "********************************************"<<endl;
			cout << "****             1.姓名               ******" << endl;
			cout << "****             2.班级               ******" << endl;
			cout << "****             3.成绩               ******" << endl;
			cout << "********************************************"<<endl;
			cout << "你要修改该同学：" << endl;
			int choice_mod;
			cin >> choice_mod;
			if (choice_mod == 1) {
				cout << "请输入该同学正确的名字：" << endl;
				string temp_name;
				cin >> temp_name;
				m_StuArray[index]->m_name = temp_name;
				cout << "修改成功！" << endl;
			}
			else if (choice_mod == 2) {
				cout << "请输入该同学正确的班级：" << endl;
				string temp_class;
				cin >> temp_class;
				m_StuArray[index]->m_class = temp_class;
				cout << "修改成功！" << endl;
			}
			else if (choice_mod == 3) {
				
				cout << "********************************************"<<endl;
				cout << "****             1.c/c++              ******" << endl;
				cout << "****             2.高数               ******" << endl;
				cout << "****             3.模电               ******" << endl;
				cout << "****             4.数电               ******" << endl;
				cout << "****             5.python             ******" << endl;
				cout << "****             6.java               ******" << endl;
				cout << "****             7.PHP                ******" << endl;
				cout << "********************************************"<<endl;
				cout << "请输入需要修改的课程编号：" << endl;
				int choice_mod_couerse;
				cin >> choice_mod_couerse;
				if (m_StuArray[index]->course_array[choice_mod_couerse].m_course_grade != -1) {
					cout << "请输入修改后的成绩：" << endl;
					int choice_mod_grade;
					cin >> choice_mod_grade;
					m_StuArray[index]->course_array[choice_mod_couerse].m_course_grade = choice_mod_grade;
					cout << "修改成功！" << endl;

				}
				else {
					cout << "修改失败，该学生未选这门课" << endl;
				}

			}
			else {
				cout << "输入错误！" << endl;
			}
		}
		else
		{
			cout << "修改失败，未找到该学生" << endl;
		}

	}
	system("pause");
	system("cls");
}

//查找学生 信息 
void StudentScoreMangeger::Find_Stu() {
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "********************************************"<<endl;
		cout << "****             1.按班级查找         ******" << endl;
		cout << "****             2.按姓名查找         ******" << endl;
		cout << "****             3.按学号查找         ******" << endl;
		cout << "********************************************"<<endl;
		cout << "请输入查找学生的方式：" << endl;
		int choice_find;
		string class_find;
		string name_find;
		int a,b,c,d;//优秀 良好 及格 不及格科目 
		cin >> choice_find;
		if (choice_find == 1) {
			cout << "你要查找的班级："<<endl;
			cin >> class_find;int flag1=0; 
			for (int i = 0; i < m_StuNum ; i++) {
				
					if (m_StuArray[i]->m_class == class_find) {
						m_StuArray[i]->showInfo();
						flag1=1;
					}
			}
			if(flag1==0) cout<<"查无此班"<<endl; 

		}

		else if (choice_find == 2) {
			cout << "你要查找的姓名：" << endl;
			cin >> name_find;int flag2=0; 
			for (int i = 0; i < m_StuNum; i++) {

				if (m_StuArray[i]->m_name  == name_find) {
					m_StuArray[i]->showInfo();
					flag2=1; 
				}

			}
			if(flag2==0) cout<<"查无此人"<<endl; 
		}

		else if (choice_find == 3) {

			//按学生学号查找
			cout << "请输入想要查找的学号：" << endl;
			long long  id = 0;
			cin >> id;

			int index = this->IsExist(id);//查找学生 

			if (index != -1) {//说明学生存在 
				m_StuArray[index]->showInfo();
				//成绩分析
			
				// 优势学科（  >平均分   保持住 
				// 劣势学科（  <平均分   加油 
				
				double junfen[9];
				for (int i = 1; i <=7 ; i++) {
					int num=0,sum=0;
					for (int j = 0; j < m_StuNum ; j++) {
						if (m_StuArray[j]->course_array[i].m_course_grade!=-1) {
								num++;
								sum+=m_StuArray[j]->course_array[i].m_course_grade;
						}
					junfen[i]=1.0*sum/num;
				}
			}
			cout<<endl;	
			//cout << "********************************************"<<endl;
				cout<<"优势学科如下,请继续努力：";
				for(int i=1;i<=7;i++){
					if(m_StuArray[index]->course_array [i].m_course_grade>junfen[i]){//课程序号默任代表相应课程 
					//1c/c++(4学分) 2高数（6学分） 3模电（6) 4 数电(5) 5 python(5) 6 java(4) 7 PHP(3)
						if(i==1) cout<<"c/c++"<<" ";
						if(i==2) cout<<"高数"<<" ";
						if(i==3) cout<<"模电"<<" ";
						if(i==4) cout<<"数电"<<" ";
						if(i==5) cout<<"python"<<" ";
						if(i==6) cout<<"java"<<" ";
						if(i==7) cout<<"PHP"<<" ";			
					}	
					
				}
				cout<<endl;	cout<<endl;	
				cout<<"劣势学科如下，还得加油：";
				for(int i=1;i<=7;i++){
					if(m_StuArray[index]->course_array [i].m_course_grade<=junfen[i]&&m_StuArray[index]->course_array [i].m_course_grade!=-1){//课程序号默任代表相应课程 
					//1c/c++(4学分) 2高数（6学分） 3模电（6) 4 数电(5) 5 python(5) 6 java(4) 7 PHP(3)
						if(i==1) cout<<"c/c++"<<" ";
						if(i==2) cout<<"高数"<<" ";
						if(i==3) cout<<"模电"<<" ";
						if(i==4) cout<<"数电"<<" ";
						if(i==5) cout<<"python"<<" ";
						if(i==6) cout<<"java"<<" ";
						if(i==7) cout<<"PHP"<<" ";				
					}	
				
				}
				//cout << "********************************************"<<endl;
				cout<<endl;	

			}
			else {
				cout << "查找失败，未找到这位学生。";
			}
			///
		}

		else {
			cout << "输入错误！" << endl;
		}

	}
	system("pause");
	system("cls");
}

//展示学生信息 
void XT_student::showInfo() {
	cout <<"学院:" << this->getXueYuan()
			<< '\t'<< '\t'<<"班级:" << this->m_class
		<< '\t'<<"姓名:" << this->m_name
		<< '\t'<<"学号:" << this->m_id
		<< '\t'<<"c/c++成绩:" << this->course_array[1].m_course_grade
		<< '\t'<<"高数成绩:" << this->course_array[2].m_course_grade
		<< '\t'<<"模电成绩:" << this->course_array[3].m_course_grade
		<< '\t'<<"数电成绩:" << this->course_array[4].m_course_grade << endl;
}
	string XT_student::getXueYuan() {
		return string("信息与通信工程学院");
}

//展示学生信息
void JW_student::showInfo() {
	cout<< "学院:" << this->getXueYuan()
		<< '\t'<<"班级:" << this->m_class
		<< '\t'<<"姓名:" << this->m_name
		<< '\t'<<"学号:" << this->m_id
	    << '\t'<<"c/c++成绩:" << this->course_array[1].m_course_grade
		<< '\t'<<"Python成绩:" << this->course_array[5].m_course_grade
		<< '\t'<<" Java成绩:" << this->course_array[6].m_course_grade
		<< '\t'<<" PHP成绩:" << this->course_array[7].m_course_grade << endl;
}
	string JW_student::getXueYuan() {
		return string("计算机与网络安全学院");
}


//退出程序函数 
void StudentScoreMangeger::exitSystem() {
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}


int main() {
	StudentScoreMangeger ssm;
	int choice = 0;
	cout << "********************************************"<<endl;
	cout<<"****             1.教师               ******"<<endl; 
	cout<<"****             2.学生               ******"<<endl; 
	cout << "********************************************"<<endl;
	cout<<"请输入您的身份："<<endl; 
	int identy;
	cin>> identy;
	system("cls");
	while (true)
	{
		//展示菜单。
		if(identy==1)ssm.Show_Menu_tea();
		else ssm.Show_Menu_stu();	
			
		cout << "请输入您的选择: " << endl;
		cin >> choice;
		switch (choice)
		{
			//退出管理程序。	
		case 0:
			ssm.exitSystem();
			break;
			//1.录入学生成绩。	
		case 1:
			ssm.Add_Stu();
			break;
			//2.删除学生成绩。	
		case 2:
			ssm.Del_Stu();
			break;
			//3.修改学生成绩。	
		case 3:
			ssm.Mod_Stu();
			break;
			//4.浏览学生成绩。	
		case 4:
			ssm.Show_Stu();
			break;
			//5.查找学生成绩。	
		case 5:
			ssm.Find_Stu();
			break;
			//6.统计成绩排序。	
		case 6:
			ssm.Sort_Stu();
			break;
			//7.清空所有文档。	
		case 7:
			ssm.Clean_File();
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}
