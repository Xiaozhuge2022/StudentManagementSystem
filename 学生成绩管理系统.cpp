#include<iostream> 
#include<iomanip> 
#include<cstring>
#include<algorithm>
#include<fstream> 
#include<cmath>
using namespace std;
#define  FILENAME "stuFile.txt"//�ļ�·�����Ϊ�곣��


//�����γ�course���� 
class course {
public:
	course() {
		m_course_id = -1;
		m_course_grade = -1;
		m_course_credit = 2;///Ĭ����ѧ�� �Կ�������� 

	}
	int m_course_id;//
	int  m_course_grade;//�γ̳ɼ� 
	int m_course_credit;//�γ�ѧ�� 

};


//����cucerѧ������ 
class CUCer {
public:
	virtual void showInfo() = 0;//��ʾ������Ϣ
	virtual string getXueYuan() = 0;// ��ʾѧԺ 
	string m_name;
	long long  m_id;
	int m_XueYuanid;//ѧ������ѧԺid 
	string m_class;//�༶ 
	int sum_score;//�ܷ� 
	double GPA;
	course course_array[20];//ÿλѧ���ж��ſ�  ����Ͱ���� ��˼�� �γ������±���ǿγ� id 
};


//������ͨ��XT��ѧ���� �̳�cucerѧ�����ࡣ
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
	//���γ���� �ɼ� ѧ�ֳ�ʼ�� 
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
	if (c1 + c2 + c3 + c4 != 0)//����GPA 
		GPA = 1.0*(s1 * c1 + s2 * c2 + s3 * c3 + s4 * c4) / ((c1 + c2 + c3 + c4)*20);
}


//����������JW��ѧ���� �̳�cucerѧ�����ࡣ 	
class JW_student : public CUCer {
public:
	friend class  StudentScoreMangeger;
	virtual void showInfo();  //��̬չʾ��Ϣ���� 
	virtual string getXueYuan();
	JW_student(string tempclass, string name, long long id, int s1, int c1, int s2, int c2, int s3, int c3, int s4, int c4, int XueYuanid);

};
JW_student::JW_student(string tempclass, string name, long long id, int s1, int c1, int s2, int c2, int s3, int c3, int s4, int c4, int XueYuanid) {
	this->m_class = tempclass;
	this->m_name = name;
	this->m_id = id;
	this->m_XueYuanid = XueYuanid;
	//���γ���� �ɼ� ѧ�ֳ�ʼ�� 
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
		GPA = 1.0*(s1 * c1 + s2 * c2 + s3 * c3 + s4 * c4) / ((c1 + c2 + c3 + c4)*20);//ǧ��ע�� 
}


//����ѧ���ɼ�����ϵͳ��
class  StudentScoreMangeger {

public:
	//���캯�� 
	StudentScoreMangeger();

	//¼��ѧ����Ϣ 
	void Add_Stu();

	//�����ļ� 
	void save();

	//��ʼ��ѧ�� 
	void init_Stu();

	//ͳ������
	int get_StuNum();

	//�������ѧ����Ϣ
	void Show_Stu();

	//�Ƴ����� 
	void exitSystem();

	//չʾ�˵� 
	void Show_Menu_tea();
	void Show_Menu_stu(); 

	//ɾ��ѧ����Ϣ 
	void Del_Stu();

	//����ļ�
	void Clean_File();

	//ѧ������ 
	void Sort_Stu();

	//����ѧ�� 
	void Find_Stu();

	//�޸�ѧ�� 
	void Mod_Stu();

	//����ѧ������ж��Ƿ����,�����ڷ�����������λ�ã������ڷ���-1
	int IsExist(long long id);

	~StudentScoreMangeger() {
		if (this->m_StuArray != NULL)
		{
			delete[] this->m_StuArray;
		}
	}
	bool m_FileIsEmpty;////��־�ļ��Ƿ�Ϊ��
	int m_StuNum;//��¼��ѧ������ 
	CUCer** m_StuArray;// ѧ�������ָ��
};

//ѧ���ɼ�����ϵͳ�� Ĭ�Ϲ��캯�� 
StudentScoreMangeger::StudentScoreMangeger() {

	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	//�ļ����������
	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl; //�������
		this->m_StuNum = 0;  //��ʼ������
		this->m_FileIsEmpty = true; //��ʼ���ļ�Ϊ�ձ�־
		this->m_StuArray = NULL; //��ʼ������
		ifs.close(); //�ر��ļ�
		return;
	}

	//�ļ����ڣ�����û�м�¼
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ��!" << endl;
		this->m_StuNum = 0;
		this->m_FileIsEmpty = true;
		this->m_StuArray = NULL;
		ifs.close();
		return;
	}
	int num = this->get_StuNum();
	//cout << "ѧ������Ϊ��" << num << endl;  //���Դ���
	this->m_StuNum = num;  //���³�Ա���� 

	//����ѧ������������
	this->m_StuArray = new CUCer * [this->m_StuNum];
	//��ʼ��ְ��
	init_Stu();

}

//�����ļ�
void StudentScoreMangeger::save() {

	ofstream ofs;
	ofs.open(FILENAME, ios::out);


	for (int i = 0; i < this->m_StuNum; i++)
	{
		if(m_StuArray[i] ->m_XueYuanid ==1)  //��ͨѧԺ 
			ofs << this->m_StuArray[i]->m_XueYuanid << " "
				<< this->m_StuArray[i]->m_class << " "
				<< this->m_StuArray[i]->m_name << " "
				<< this->m_StuArray[i]->m_id << " "

				<< this->m_StuArray[i]->course_array[1].m_course_grade << " "
				<< this->m_StuArray[i]->course_array[2].m_course_grade << " "
				<< this->m_StuArray[i]->course_array[3].m_course_grade << " "
				<< this->m_StuArray[i]->course_array[4].m_course_grade << endl;
		else {//����ѧԺ 
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

//��ʾ�˵� ��ʦ��ҳ�� 
void StudentScoreMangeger::Show_Menu_tea() {

	cout << "********************************************" << endl;
	cout << "******  ��ӭʹ��CUCѧ���ɼ�����ϵͳ�� ******" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.¼��ѧ���ɼ�  *************" << endl;
	cout << "*************  2.ɾ��ѧ���ɼ�  *************" << endl;
	cout << "*************  3.�޸�ѧ����Ϣ  *************" << endl;
	cout << "*************  4.���ѧ���ɼ�  *************" << endl;
	cout << "*************  5.����ѧ���ɼ�  *************" << endl;
	cout << "*************  6.ͳ�Ƴɼ�����  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}


//��ʾ�˵� ѧ����ҳ�� 
void StudentScoreMangeger::Show_Menu_stu() {

	cout << "********************************************" << endl;
	cout << "******  ��ӭʹ��CUCѧ���ɼ�����ϵͳ�� ******" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  4.���ѧ���ɼ�  *************" << endl;
	cout << "*************  5.����ѧ���ɼ�  *************" << endl;
	cout << "*************  6.ͳ�Ƴɼ�����  *************" << endl;
	cout << "*************(������������Ȩ��)**************" << endl;
	cout << endl;
}
//¼��ѧ����Ϣ 
void StudentScoreMangeger::Add_Stu() {
	cout << "����������ѧ�������� " ;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		//�����¿ռ��С
		int newSize = this->m_StuNum + addNum;

		//�����¿ռ�
		CUCer** newSpace = new CUCer * [newSize];

		//��ԭ�ռ������ݴ�ŵ��¿ռ���
		if (this->m_StuArray != NULL)
		{
			for (int i = 0; i < this->m_StuNum; i++)
			{
				newSpace[i] = this->m_StuArray[i];
			}
		}

		//����������
		for (int i = 0; i < addNum; i++)
		{
			string tempclass;
			string name;
			long long  id;
			int dSelect;
			int s1, c1, s2, c2, s3, c3, s4, c4;
            //������ʾ���������Ϣ 
			cout << "������� " << i + 1 << " ����ѧ���༶��" <<endl;
			cin >> tempclass;
			cout << "������� " << i + 1 << " ����ѧ��������" <<endl;
			cin >> name;
			cout << "������� " << i + 1 << " ����ѧ��ѧ��(13λ)��" <<endl;
			cin >> id;

			cout << "������� " << i + 1 << " ����ѧ��4�ſμ�ѧ�֣�" <<
			" (���� ���ɼ�1 ѧ��1 �ɼ�2 ѧ��2......)" <<endl;
			
			cin >> s1;
			cin >> c1;
			cin >> s2;
			cin >> c2;
			cin >> s3;
			cin >> c3;
			cin >> s4;
			cin >> c4;
            cout << "�����������ѧԺ��" << endl;
		
			cout << "1.��Ϣ��ͨ�Ź���ѧԺ  " << endl;
			cout << "2.����������簲ȫѧԺ  " << endl;
			
			cin >> dSelect;

			CUCer* cucer = NULL;
			switch (dSelect)
			{
			case 1: //��ͨ 
				cucer = new XT_student(tempclass, name, id, s1, c1, s2, c2, s3, c3, s4, c4, 1);
				break;
			case 2: //���� 
				cucer = new JW_student(tempclass, name, id, s1, c1, s2, c2, s3, c3, s4, c4, 2);
				break;
			default:
				break;
			}
			newSpace[this->m_StuNum + i] = cucer;
		}

		//�ͷ�ԭ�пռ�
		delete[] this->m_StuArray;

		//�����¿ռ��ָ��
		this->m_StuArray = newSpace;

		//�����µĸ���
		this->m_StuNum = newSize;

		//����ְ����Ϊ�ձ�־
		this->m_FileIsEmpty = false;

		//��ʾ��Ϣ
		cout << "�ɹ����" << addNum << "����ѧ���ɼ���" << endl;

		//���浽�ļ�
		this->save();
	}
	else
	{
		cout << "��������" << endl;
	}

	system("pause");
	system("cls");
}

//��ȡ��¼��ѧ������
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
		//��¼����
		num++;
	}
	ifs.close();

	return num;
}

//��ʼ������ 
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
		//���ݲ�ͬ��ѧԺId������ͬ����
		if (Xueyuanid == 1)  // 1��ͨ
		{
			cucer = new XT_student(tclass, name, id, s11, 4, s22, 6, s33, 5, s44, 3, 1);
		}
		else  //2���� 
		{
			cucer = new JW_student(tclass, name, id, s11, 4, s22, 5, s33, 4, s44, 3, 2);
		}

		//�����������
		this->m_StuArray[index] = cucer;
		index++;
	}
}

//�ж�ѧ���Ƿ���� 
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

//��ʾ����ѧ����Ϣ 
void StudentScoreMangeger::Show_Stu() {
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < m_StuNum; i++)
		{
			//���ö�̬���ýӿ�
			this->m_StuArray[i]->showInfo();
		}
		cout<<"��¼��"<< StudentScoreMangeger::m_StuNum <<"��ѧ��"<<endl;
	}

	system("pause");
	system("cls");
}

//ɾ��ѧ����Ϣ 
void StudentScoreMangeger::Del_Stu() {
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		//��ѧ��ѧ��ɾ��
		cout << "��������Ҫɾ����ѧ�ţ�" << endl;
		long long  id = 0;
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1)  //˵��index��λ��������Ҫɾ��
		{
			for (int i = index; i < this->m_StuNum - 1; i++)
			{
				this->m_StuArray[i] = this->m_StuArray[i + 1];//���ø���ɾ���ķ��� 
			}
			this->m_StuNum--;

			this->save(); //ɾ��������ͬ�����ļ���
			cout << "ɾ���ɹ���" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ѧ��" << endl;
		}
	}

	system("pause");
	system("cls");

}

//����ļ�
void StudentScoreMangeger::Clean_File() {
	cout << "********************************************"<<endl;
	cout << "****            1��ȷ��               ******" << endl;
	cout << "****            2������               ******" << endl;
	cout << "********************************************"<<endl;
	
	cout << "ȷ����գ�" << endl;
	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//��ģʽ ios::trunc �������ɾ���ļ������´���
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
		cout << "��ճɹ���" << endl;
	}

	system("pause");
	system("cls");
}


//ͳ��ѧ���ɼ� �� ѧ������ 
void StudentScoreMangeger::Sort_Stu() {
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{	//ͳ��ѧ���ɼ�������**�༶�Ϳ�Ŀ����ƽ����**��  500  
		cout<<"********************************************"<<endl;
		cout<<"****1.ѧԺ�ڰ����пγ��ܷ�����        ******"<<endl;
		cout<<"****2.ѧԺ�ڰ�ƽ��ѧ�ּ��㣨GPA������ ******" << endl;
		cout<<"****3.�༶�ڰ������пγ��ܷ�����      ******" << endl; 
		cout<<"****4.�༶�ڰ�ƽ��ѧ�ּ��㣨GPA������ ******" << endl;
		cout<<"****5.ĳһ�ſγ̳ɼ�����              ******" << endl;  
		cout<<"********************************************"<<endl;
		cout<<"��ѡ������ʽ�� " << endl;
		string choice_class;//��¼ѡ���ѯ�İ༶
		int choice;//��¼��ѯ�ķ�ʽ12345
		cin >> choice;
		int k = 0;
		double sum_score_sort = 0;//��¼��ѯ�ܷ�  ���ڼ���ƽ����
		switch (choice) {
		case 1:

			//�����Ƕ���ָ�� ����ʹ��sort���� ֻ��ʹ�ü򵥵�ð�� ���� 
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
			cout << "****        1.��Ϣ��ͨ�Ź���ѧԺ      ******" << endl;
			cout << "****        2.����������簲ȫѧԺ    ******" << endl;
			cout << "********************************************"<<endl;
			cout << "��������Ҫ��ѯ��ѧԺ��" << endl;
			int choice_xueyuan;
			cin >> choice_xueyuan;//��¼��ѯ��ѧԺ 

			if (choice_xueyuan == 1) {
				cout << "��Ϣ��ͨ�Ź���ѧԺ����ѧ���γ��ܷ��������£�" << endl;
				for (int i = 0; i < m_StuNum; i++) {
					if (m_StuArray[i]->m_XueYuanid == 1) {//��1����ʾ����ͨ�� 
						k++;
						cout << "��" << k << "��" 
							<< '\t'<<"�༶:" << m_StuArray[i]->m_class
							<< '\t'<<"����:" << m_StuArray[i]->m_name
							<< '\t'<<"ѧ��:" << m_StuArray[i]->m_id
							<< '\t'<<"�ܷ�:" << m_StuArray[i]->sum_score << endl;
						sum_score_sort += m_StuArray[i]->sum_score;

					}
				}
			}
			else {
				cout << "����������簲ȫѧԺ����ѧ���γ��ܷ��������£�" << endl;
				for (int i = 0; i < m_StuNum; i++) {
					if (m_StuArray[i]->m_XueYuanid == 2) {//��2����ʾ�Ǽ����� 
						k++;
						cout << "��" << k << "��" 
							<< '\t'<<"�༶�� " << m_StuArray[i]->m_class
							<< '\t'<<"����:  " << m_StuArray[i]->m_name
							<< '\t'<<"ѧ�ţ� " << m_StuArray[i]->m_id
							<< '\t'<<"�ܷ֣� " << m_StuArray[i]->sum_score << endl;
						sum_score_sort += m_StuArray[i]->sum_score;
					}
				}
			}

			//���ѧԺ�γ��ܷ�ƽ����
			cout << "**ѧԺԺ�γ��ܷ�ƽ����:**" << (double)sum_score_sort / k << endl;
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
			cout << "****        1.��Ϣ��ͨ�Ź���ѧԺ      ******" << endl;
			cout << "****        2.����������簲ȫѧԺ    ******" << endl;
			cout << "********************************************"<<endl;
			cout << "��������Ҫ��ѯ��ѧԺ��" << endl;
			
			int choice_xueyuan01;

			cin >> choice_xueyuan01;
			if (choice_xueyuan01 == 1) {
				cout << "��Ϣ��ͨ�Ź���ѧԺ����ѧ��GPA�������£�" << endl;
				for (int i = 0; i < m_StuNum; i++) {
					if (m_StuArray[i]->m_XueYuanid == 1) {//��1����ʾ����ͨ�� 
						k++;
						cout << "��" << k << "��" 
							<< '\t'<<"�༶�� " << m_StuArray[i]->m_class
							<< '\t'<<"����:  " << m_StuArray[i]->m_name
							<< '\t'<<"ѧ�ţ� " << m_StuArray[i]->m_id
							<< '\t'<<"�ܷ֣� " << m_StuArray[i]->GPA << endl;
						sum_score_sort += m_StuArray[i]->GPA;

					}
				}
			}
			else {
				cout << "����������簲ȫѧԺ����ѧ��GPA�������£�" << endl;
				for (int i = 0; i < m_StuNum; i++) {
					if (m_StuArray[i]->m_XueYuanid == 2) {//��2����ʾ�Ǽ����� 
						k++;
						cout << "��" << k << "��" 
							<< '\t'<<"�༶�� " << m_StuArray[i]->m_class
							<< '\t'<<"����:  " << m_StuArray[i]->m_name
							<< '\t'<<"ѧ�ţ� " << m_StuArray[i]->m_id
							<< '\t'<<"�ܷ֣� " << m_StuArray[i]->GPA << endl;
							sum_score_sort += m_StuArray[i]->GPA;
					}
				}
			}


			//���ѧԺԺ�γ�ѧ�ּ�Ȩƽ����
			cout << "ѧԺԺ�γ�ѧ�ּ�Ȩƽ����:" << (double)sum_score_sort / k << endl;
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

			cout << "��������Ҫ��ѯ�İ༶��" << endl;
			
			cin >> choice_class;//��¼��ѯ�İ༶

			
				cout << "�ð�����ѧ���γ��ܷ��������£�" << endl;
				for (int i = 0; i < m_StuNum; i++) {
					if (m_StuArray[i]->m_class  == choice_class) {//��ʾ�������ͬѧ 
						k++;
						cout << "��" << k << "��" 
							<< '\t'<<"�༶�� " << m_StuArray[i]->m_class
							<< '\t'<<"����:  " << m_StuArray[i]->m_name
							<< '\t'<<"ѧ�ţ� " << m_StuArray[i]->m_id
							<< '\t'<<"�ܷ֣� " << m_StuArray[i]->sum_score << endl;
						    sum_score_sort += m_StuArray[i]->sum_score;
					}
				}
				//����༶�γ��ܷ�ƽ����
				cout << "�༶�γ�ѧ��ƽ����:" << (double)sum_score_sort / k << endl;

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

			cout << "��������Ҫ��ѯ�İ༶��" << endl;
			
			cin >> choice_class;//��¼��ѯ��ѧԺ 


			cout << "�ð�����ѧ���γ̼�Ȩƽ�����������£�" << endl;
			for (int i = 0; i < m_StuNum; i++) {
				if (m_StuArray[i]->m_class == choice_class) {//��ʾ�������ͬѧ 
					k++;
					cout << "��" << k << "��"
						<< '\t'<<"�༶�� " << m_StuArray[i]->m_class
						<< '\t'<<"����:  " << m_StuArray[i]->m_name
						<< '\t'<<"ѧ�ţ� " << m_StuArray[i]->m_id
						<< '\t'<<"�ܷ֣� " << m_StuArray[i]->GPA << endl;
					sum_score_sort += m_StuArray[i]->GPA;

				}
			}
			//����༶�γ��ּܷ�Ȩƽ����
			cout << "�༶�γ̼�Ȩƽ����:" << (double)sum_score_sort / k << endl;
			break;
		case 5:
				cout << "********************************************"<<endl;
				cout << "****             1.c/c++              ******" << endl;
				cout << "****             2.����               ******" << endl;
				cout << "****             3.ģ��               ******" << endl;
				cout << "****             4.����               ******" << endl;
				cout << "****             5.python             ******" << endl;
				cout << "****             6.java               ******" << endl;
				cout << "****             7.PHP                ******" << endl;
				cout << "********************************************"<<endl;
			cout << "��������Ҫ�����Ŀγ���ţ�" << endl;
			int choice_class05;
			cin >> choice_class05;//��¼��ѡ�Ŀγ���� 
			 //���������ſγɼ�ȫ�ţ�ûѡ�ε��˳ɼ�Ϊ-1 
			for (int i = 0; i < m_StuNum - 1; i++) {
				for (int j = 0; j < m_StuNum - i - 1; j++) {
					if (m_StuArray[j]->course_array[choice_class05].m_course_grade < m_StuArray[j + 1]->course_array[choice_class05].m_course_grade) {
						CUCer* temp = m_StuArray[j];
						m_StuArray[j] = m_StuArray[j + 1];
						m_StuArray[j + 1] = temp;
					}
				}
			}
			cout << "ѡ���ſε��˰��ճɼ�����Ϊ��" << endl;

			for (int i = 0; i < m_StuNum; i++) {
				if (m_StuArray[i]->course_array[choice_class05].m_course_grade != -1) {//�ų�ûѡ�ε��� ���ɼ�Ϊ-1 �� 
					k++;

					cout << "��" << k << "��"
						<< '\t'<<"ѧԺ�� " << m_StuArray[i]->getXueYuan()
						<< '\t'<<"�༶�� " << m_StuArray[i]->m_class
						<< '\t'<<"����:  " << m_StuArray[i]->m_name
						<< '\t'<<"ѧ�ţ� " << m_StuArray[i]->m_id
						<< '\t'<<"�ɼ��� " << m_StuArray[i]->course_array[choice_class05].m_course_grade << endl;
					sum_score_sort += m_StuArray[i]->course_array[choice_class05].m_course_grade;
				}
			}

			//����༶ƽ����
			
			cout << "**�γ�ƽ����:**" << (double)sum_score_sort / k << endl;
			break;
		default:
			cout << "�������" << endl;
			break;
		}

		system("pause");
		system("cls");
	}


}

//�޸�ѧ����Ϣ 
void StudentScoreMangeger::Mod_Stu() {
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");
	}
	else {
		//��ѧ��ѧ���޸� 
		cout << "��������Ҫ�޸ĵ�ѧ�ţ�" << endl;
		long long  id = 0;
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1) {  //˵��index��λ��������Ҫ�޸� 
			cout << "********************************************"<<endl;
			cout << "****             1.����               ******" << endl;
			cout << "****             2.�༶               ******" << endl;
			cout << "****             3.�ɼ�               ******" << endl;
			cout << "********************************************"<<endl;
			cout << "��Ҫ�޸ĸ�ͬѧ��" << endl;
			int choice_mod;
			cin >> choice_mod;
			if (choice_mod == 1) {
				cout << "�������ͬѧ��ȷ�����֣�" << endl;
				string temp_name;
				cin >> temp_name;
				m_StuArray[index]->m_name = temp_name;
				cout << "�޸ĳɹ���" << endl;
			}
			else if (choice_mod == 2) {
				cout << "�������ͬѧ��ȷ�İ༶��" << endl;
				string temp_class;
				cin >> temp_class;
				m_StuArray[index]->m_class = temp_class;
				cout << "�޸ĳɹ���" << endl;
			}
			else if (choice_mod == 3) {
				
				cout << "********************************************"<<endl;
				cout << "****             1.c/c++              ******" << endl;
				cout << "****             2.����               ******" << endl;
				cout << "****             3.ģ��               ******" << endl;
				cout << "****             4.����               ******" << endl;
				cout << "****             5.python             ******" << endl;
				cout << "****             6.java               ******" << endl;
				cout << "****             7.PHP                ******" << endl;
				cout << "********************************************"<<endl;
				cout << "��������Ҫ�޸ĵĿγ̱�ţ�" << endl;
				int choice_mod_couerse;
				cin >> choice_mod_couerse;
				if (m_StuArray[index]->course_array[choice_mod_couerse].m_course_grade != -1) {
					cout << "�������޸ĺ�ĳɼ���" << endl;
					int choice_mod_grade;
					cin >> choice_mod_grade;
					m_StuArray[index]->course_array[choice_mod_couerse].m_course_grade = choice_mod_grade;
					cout << "�޸ĳɹ���" << endl;

				}
				else {
					cout << "�޸�ʧ�ܣ���ѧ��δѡ���ſ�" << endl;
				}

			}
			else {
				cout << "�������" << endl;
			}
		}
		else
		{
			cout << "�޸�ʧ�ܣ�δ�ҵ���ѧ��" << endl;
		}

	}
	system("pause");
	system("cls");
}

//����ѧ�� ��Ϣ 
void StudentScoreMangeger::Find_Stu() {
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "********************************************"<<endl;
		cout << "****             1.���༶����         ******" << endl;
		cout << "****             2.����������         ******" << endl;
		cout << "****             3.��ѧ�Ų���         ******" << endl;
		cout << "********************************************"<<endl;
		cout << "���������ѧ���ķ�ʽ��" << endl;
		int choice_find;
		string class_find;
		string name_find;
		int a,b,c,d;//���� ���� ���� �������Ŀ 
		cin >> choice_find;
		if (choice_find == 1) {
			cout << "��Ҫ���ҵİ༶��"<<endl;
			cin >> class_find;int flag1=0; 
			for (int i = 0; i < m_StuNum ; i++) {
				
					if (m_StuArray[i]->m_class == class_find) {
						m_StuArray[i]->showInfo();
						flag1=1;
					}
			}
			if(flag1==0) cout<<"���޴˰�"<<endl; 

		}

		else if (choice_find == 2) {
			cout << "��Ҫ���ҵ�������" << endl;
			cin >> name_find;int flag2=0; 
			for (int i = 0; i < m_StuNum; i++) {

				if (m_StuArray[i]->m_name  == name_find) {
					m_StuArray[i]->showInfo();
					flag2=1; 
				}

			}
			if(flag2==0) cout<<"���޴���"<<endl; 
		}

		else if (choice_find == 3) {

			//��ѧ��ѧ�Ų���
			cout << "��������Ҫ���ҵ�ѧ�ţ�" << endl;
			long long  id = 0;
			cin >> id;

			int index = this->IsExist(id);//����ѧ�� 

			if (index != -1) {//˵��ѧ������ 
				m_StuArray[index]->showInfo();
				//�ɼ�����
			
				// ����ѧ�ƣ�  >ƽ����   ����ס 
				// ����ѧ�ƣ�  <ƽ����   ���� 
				
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
				cout<<"����ѧ������,�����Ŭ����";
				for(int i=1;i<=7;i++){
					if(m_StuArray[index]->course_array [i].m_course_grade>junfen[i]){//�γ����Ĭ�δ�����Ӧ�γ� 
					//1c/c++(4ѧ��) 2������6ѧ�֣� 3ģ�磨6) 4 ����(5) 5 python(5) 6 java(4) 7 PHP(3)
						if(i==1) cout<<"c/c++"<<" ";
						if(i==2) cout<<"����"<<" ";
						if(i==3) cout<<"ģ��"<<" ";
						if(i==4) cout<<"����"<<" ";
						if(i==5) cout<<"python"<<" ";
						if(i==6) cout<<"java"<<" ";
						if(i==7) cout<<"PHP"<<" ";			
					}	
					
				}
				cout<<endl;	cout<<endl;	
				cout<<"����ѧ�����£����ü��ͣ�";
				for(int i=1;i<=7;i++){
					if(m_StuArray[index]->course_array [i].m_course_grade<=junfen[i]&&m_StuArray[index]->course_array [i].m_course_grade!=-1){//�γ����Ĭ�δ�����Ӧ�γ� 
					//1c/c++(4ѧ��) 2������6ѧ�֣� 3ģ�磨6) 4 ����(5) 5 python(5) 6 java(4) 7 PHP(3)
						if(i==1) cout<<"c/c++"<<" ";
						if(i==2) cout<<"����"<<" ";
						if(i==3) cout<<"ģ��"<<" ";
						if(i==4) cout<<"����"<<" ";
						if(i==5) cout<<"python"<<" ";
						if(i==6) cout<<"java"<<" ";
						if(i==7) cout<<"PHP"<<" ";				
					}	
				
				}
				//cout << "********************************************"<<endl;
				cout<<endl;	

			}
			else {
				cout << "����ʧ�ܣ�δ�ҵ���λѧ����";
			}
			///
		}

		else {
			cout << "�������" << endl;
		}

	}
	system("pause");
	system("cls");
}

//չʾѧ����Ϣ 
void XT_student::showInfo() {
	cout <<"ѧԺ:" << this->getXueYuan()
			<< '\t'<< '\t'<<"�༶:" << this->m_class
		<< '\t'<<"����:" << this->m_name
		<< '\t'<<"ѧ��:" << this->m_id
		<< '\t'<<"c/c++�ɼ�:" << this->course_array[1].m_course_grade
		<< '\t'<<"�����ɼ�:" << this->course_array[2].m_course_grade
		<< '\t'<<"ģ��ɼ�:" << this->course_array[3].m_course_grade
		<< '\t'<<"����ɼ�:" << this->course_array[4].m_course_grade << endl;
}
	string XT_student::getXueYuan() {
		return string("��Ϣ��ͨ�Ź���ѧԺ");
}

//չʾѧ����Ϣ
void JW_student::showInfo() {
	cout<< "ѧԺ:" << this->getXueYuan()
		<< '\t'<<"�༶:" << this->m_class
		<< '\t'<<"����:" << this->m_name
		<< '\t'<<"ѧ��:" << this->m_id
	    << '\t'<<"c/c++�ɼ�:" << this->course_array[1].m_course_grade
		<< '\t'<<"Python�ɼ�:" << this->course_array[5].m_course_grade
		<< '\t'<<" Java�ɼ�:" << this->course_array[6].m_course_grade
		<< '\t'<<" PHP�ɼ�:" << this->course_array[7].m_course_grade << endl;
}
	string JW_student::getXueYuan() {
		return string("����������簲ȫѧԺ");
}


//�˳������� 
void StudentScoreMangeger::exitSystem() {
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}


int main() {
	StudentScoreMangeger ssm;
	int choice = 0;
	cout << "********************************************"<<endl;
	cout<<"****             1.��ʦ               ******"<<endl; 
	cout<<"****             2.ѧ��               ******"<<endl; 
	cout << "********************************************"<<endl;
	cout<<"������������ݣ�"<<endl; 
	int identy;
	cin>> identy;
	system("cls");
	while (true)
	{
		//չʾ�˵���
		if(identy==1)ssm.Show_Menu_tea();
		else ssm.Show_Menu_stu();	
			
		cout << "����������ѡ��: " << endl;
		cin >> choice;
		switch (choice)
		{
			//�˳��������	
		case 0:
			ssm.exitSystem();
			break;
			//1.¼��ѧ���ɼ���	
		case 1:
			ssm.Add_Stu();
			break;
			//2.ɾ��ѧ���ɼ���	
		case 2:
			ssm.Del_Stu();
			break;
			//3.�޸�ѧ���ɼ���	
		case 3:
			ssm.Mod_Stu();
			break;
			//4.���ѧ���ɼ���	
		case 4:
			ssm.Show_Stu();
			break;
			//5.����ѧ���ɼ���	
		case 5:
			ssm.Find_Stu();
			break;
			//6.ͳ�Ƴɼ�����	
		case 6:
			ssm.Sort_Stu();
			break;
			//7.��������ĵ���	
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
