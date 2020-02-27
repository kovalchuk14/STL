#include<iostream>
#include<string>
#include<regex>

class Human
{
	std::string last_name;	//Surname
	std::string first_name;	//Name
	unsigned int age;
public:
	const std::string& get_last_name() const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	const unsigned int get_age()const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		//std::regex exp("\\w");
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}

	//			Constructors:
	Human(const std::string& last_name, const std::string first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		std::cout << "HConstructor:\t" << this << std::endl;
	}
	virtual ~Human()
	{
		std::cout << "HDestructor:\t" << this << std::endl;
	}

	virtual void print()
	{
		//std::ios_base::left;
		std::cout.width(8);
		std::cout << last_name << "\t";
		std::cout.width(8);
		std::cout << first_name << "\t";
		std::cout.width(8);
		std::cout << age << std::endl;
	}
};

class Student :public Human
{
	std::string spec;
	std::string group;
	unsigned int rating;
	unsigned int attendence;
public:
	const std::string& get_specialty()const
	{
		return spec;
	}
	const std::string& get_group()const
	{
		return group;
	}
	unsigned int get_rating()const
	{
		return rating;
	}
	unsigned int get_attendence()const
	{
		return attendence;
	}

	void set_specialty(const std::string& spec)
	{
		this->spec = spec;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(unsigned int rating)
	{
		this->rating = rating <= 100 ? rating : 100;
	}
	void set_attendence(unsigned int attendence)
	{
		this->attendence = attendence <= 100 ? attendence : 100;
	}

	//			Constructors:
	Student
	(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& spec, const std::string& group, unsigned int rating = 0, unsigned int attendence = 0
	) :Human(last_name, first_name, age)
	{
		set_specialty(spec);
		set_group(group);
		set_rating(rating);
		set_attendence(attendence);
		std::cout << "SConstructor:\t" << this << std::endl;
	}
	~Student()
	{
		std::cout << "SDestructor:\t" << this << std::endl;
	}

	void print()
	{
		Human::print();
		std::cout << spec << "\t" << group << ", ������������ " << rating << "%, ������������ " << attendence << "%\n";
	}
};

class Teacher :public Human
{
	std::string subject;
	unsigned int experience;
	unsigned int evil;
public:
	const std::string& get_subject()const
	{
		return subject;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	unsigned int get_evil()const
	{
		return evil;
	}
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}
	void set_experience(unsigned int number_of_groups)
	{
		this->experience = number_of_groups;
	}
	void set_evil(unsigned int evil)
	{
		this->evil = evil;
	}

	//		Constructors:
	Teacher
	(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& subject, unsigned int number_of_groups, unsigned int evil = 20
	) :Human(last_name, first_name, age)
	{
		set_subject(subject);
		set_experience(number_of_groups);
		set_evil(evil);
		std::cout << "TConstructor:\t" << this << std::endl;
	}
	~Teacher()
	{
		std::cout << "TDestructor:\t" << this << std::endl;
	}
	void print()
	{
		Human::print();
		std::cout << "�������: " << subject
			<< ", ���������� �����: " << experience
			<< ", ������� ������: " << evil << std::endl;
	}
};

class Graduate :public Student
{
	std::string diploma_theme;
	std::string curator;
	void set_diploma_theme(const std::string& diploma_theme)
	{
		this->diploma_theme = diploma_theme;
	}
public:
	const std::string& get_diploma_theme()const
	{
		return diploma_theme;
	}
	const std::string& get_curator()const
	{
		return curator;
	}
	void set_curator(const std::string& curator)
	{
		this->curator = curator;
	}

	//			Constructors:
	Graduate
	(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& spec, const std::string& group, unsigned int rating, unsigned int attendence,
		const std::string& diploma_theme, const std::string& curator
	) :
		Student
		(
			last_name, first_name, age,
			spec, group, rating, attendence
		)
	{
		set_diploma_theme(diploma_theme);
		set_curator(curator);
		std::cout << "GConstructor:\t" << this << std::endl;
	}
	~Graduate()
	{
		std::cout << "GDestructor:\t" << this << std::endl;
	}

	void print()
	{
		Student::print();
		std::cout << "Diploma theme: " << diploma_theme << ", curator: " << curator << std::endl;
	}
};

class Car
{
	class Tank
	{
		int volume;
		double fuel;
	}tank;
	class Engine
	{
		double volume;
		int power;
	}engine;
};

//#define POLYMORPHISM
//#define REGEX_NAME
#define REGEX_GROUP

void main()
{
	setlocale(LC_ALL, "");
	/*Human human("�������123", "������????", 18);
	human.print();

	Student stud("�������", "������", 18, "������", "�� �� 37");
	stud.print();

	Teacher("Einstein", "Albert", 141, "Astronomy", 5, 5).print();

	Graduate tommy("Vercetti", "Tom", 30, "Mercenary", "extreme killers", 95, 70, "How to kill Diaz", "Colonel Cortez");
	tommy.print();*/

#ifdef POLYMORPHISM
	Human* group[] =
	{
		new Student("���������23", "�����??", 15, "���", "�� �� 35", 95, 100),
		new Student("�������", "�����", 15, "���", "�� �� 35", 85, 97),
		new Teacher("�����������", "������", 42, "Hardware&Windows", 5, 0),
		new Student("��������", "������", 16, "���", "�� �� 35", 99, 100),
		new Graduate("������", "������", 17, "���", "�� �� 35", 95, 100, "3D Shooter development", "OA"),
		new Teacher("�����", "����", 35, "C++", 5, 32),
		new Graduate("�����", "��������", 22, "���", "�� ��� 35", 96, 100, "���������� ���� ��� Android", "Some teacher")
	};

	std::cout << "-----------------------------------------------------------\n";
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		group[i]->print();
		std::cout << "-----------------------------------------------------------\n";
	}

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		delete group[i];
	}
#endif // POLYMORPHISM

#ifdef REGEX_NAME
	std::string name;
	std::cout << "Input name: "; std::cin >> name;
	std::regex rgx("[A-Z][a-z]{1,20}");
	std::cout << std::regex_match(name, rgx, std::regex_constants::match_default) << std::endl;
#endif // REGEX_NAME

#ifdef REGEX_GROUP
	std::regex rgx("(ST|PS(_| )(SB|VS))[_ \-](PU|PV|ITU|ITV|DU|DV)[_ \-]\\d{2}[abv]?");
	/*std::string group1 = "ST_PV_35";
	std::string group2 = "ST PV 35";
	std::cout << std::regex_match(group1, rgx, std::regex_constants::match_default) << std::endl;
	std::cout << std::regex_match(group2, rgx, std::regex_constants::match_default) << std::endl;*/
	std::string group;
	std::cout << "Input group: "; //std::cin >> group;
	getline(std::cin, group);
	std::regex rgx_replace(" |\-");
	group = std::regex_replace(group, rgx_replace, "_", std::regex_constants::match_default);
	std::cout << std::regex_match(group, rgx, std::regex_constants::match_default) << std::endl;
	std::cout << group << std::endl;
#endif
}