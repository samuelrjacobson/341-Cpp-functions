/* compute pi using first n terms of infinite sum */
double compute_pi(int n)
{
    double sum = 0.0;
    double denom = 1.0;
    double val;
    for (int i = 1; i <= n; i++)
    {
        val = 4.0 / denom; /* calculate value of term i */
        if (i % 2 == 0) val *= -1.0; /* flip sign for every other term */
        sum += val; /* add value to sum */
        denom += 2; /* increment denominator for next term */
    }
    return sum;
}
/* receive test scores and display summary data */
void process_scores()
{	
	string name;
	int score;
	int min;
    string min_name;
    int max;
    string max_name;
    double avg = 0;
    int count_students = 0;

    while (true)
    {
        cout << "Enter a name and score: ";
        cin >> name; /* get name */

        if (name == "-1") break; /* quit when user inputs -1 */

		cin >> score; /* get score */

        /* set variables in first iteration */
        if (count_students == 0)
        {
            min_name = name;
            max_name = name;
            min = score;
            max = score;
        }
        else
        {
            if (score < min) /* Find minimum score */
            {
                min = score;
                min_name = name;
            }
            if (score > max) /* Find maximum score */
            {
                max = score;
                max_name = name;
            }
        }
        avg += score; /* calculate average */
        count_students++;
    }
    avg /= count_students;

    /* display summary data */
    cout << "Average: " << avg << "\nMinimum: " << min << "\nMaximum: " << max << "\n";
    cout << "Student with lowest score: " << min_name << "\n";
    cout << "Student with highest score: " << max_name << "\n";
}
/* read student information from file, sort and output to file */
void file_sort(char *infile, char *outfile)
{
	ifstream fin(infile); /* open file for reading */
	int num_students;
	fin >> num_students; /* get number of students */ 
    
	/* create arrays for data */
	int id[num_students];
	char grade[num_students];
	double gpa[num_students];


    /* read values to arrays */
    for (int i = 0; i < num_students; i++)
    {
        fin >> id[i]; /* add value to id array */
        char ch = ' ';
        /*while (isspace(ch))  discard whitespace 
        {
            ch = getc(in);
        }*/
        fin >> grade[i]; /* add value to grade array */
        fin >> gpa[i]; /* add value to gpa array */
    }

    /* insertion sort by id */
    for (int i = 1; i < num_students; i++)
    {
        int id_to_sort = id[i];
        char grade_to_sort = grade[i];
        double gpa_to_sort = gpa[i];

		int j;
        for(j = i - 1; j >= 0; j--)
        {
           if(id[j] < id_to_sort) break;
           id[j + 1] = id[j];
           grade[j + 1] = grade[j];
           gpa[j + 1] = gpa[j];
        }
        id[j + 1] = id_to_sort;
        grade[j + 1] = grade_to_sort;
        gpa[j + 1] = gpa_to_sort;
    }

	/* write info to output file */
	ofstream fout(outfile);
	fout << num_students << "\n";
    for(int i = 0; i < num_students; i++)
    {
        fout << id[i] << " " << grade[i] << " " << gpa[i] << "\n";
    }

    fin.close();
    fout.close();
}
/* Class Rectangle defines a Rectangle */
class Rectangle
{
	private:
		int width;
		int height;
	public:
		Rectangle();
		Rectangle(int size);
		Rectangle(int width, int height);
		void set_width(int w);
		void set_height(int h);
		int get_width();
		int get_height();
		int area();
		void display();
	
	Rectangle::Rectangle()
	{
		width = 0;
		height = 0;
	}
	Rectangle::Rectangle(int size)
	{
		width = size;
		height = size;
	}
	Rectangle::Rectangle(int width, int height)
	{
		this->width = width;
		this->height = height;
	}
	void Rectangle::set_width(int w)
	{
		width = w;
	}
	void Rectangle::set_height(int h)
	{
		height = h;
	}
	int Rectangle::get_width()
	{
		return width;
	}
	int Rectangle::get_height()
	{
		return height;
	}
	int Rectangle::area()
	{
		return width * height;
	}
	void Rectangle::display()
	{
		cout << "Width is " << width << " and height is " << height;
	}
};
/* Class Score defines a score */
class Score
{
	private:
		double num_students;
		double scores[];

	public:
		Score(int n, int scores[]);
		~Score();
		double average();
		void display();

	/* constructor */
	Score::Score(int n, int scores[])
	{
		num_students = n;
		for (int i = 0; i < scores.length; i++)
			this->scores[i] = scores[i];
	}

	/* destructor */
	Score::~Score()
	{
		delete[] score;
	}

	/* return average */
	double Score::average()
	{
		return average;
	}

	/* print data */
	void Score::display()
	{
		cout << "The scores are:\n";
		for (int i = 0; i < scores.length; i++)
		{
			cout << scores[i] << "\n";
		}
		cout << "The average score is " << average;
	}
};
/* Class Person defines a Person */
class Person
{
	private:
		string name;
		int age;
	public:
		Person(string name, int age);
		void set_name(string name);
		void set_age(int age);
		int get_name();
		int get_age();
		void show();
		
	/* constructor */
	Person::Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	
	/* setters */
	void Person::set_name(string name)
	{
		this->name = name;
	}
	void Person::set_age(int age)
	{
		this->age = age;
	}
	
	/* getters */
	int Person::get_name()
	{
		return name;
	}
	int Person::get_age()
	{
		return age;
	}
	
	/* print data */
	void Person::show()
	{
		cout << "Name: " << name << "\nAge: " << age << "\n";
	}
};
/* Student class defines student, inherits name and age from Person */
class Student : public Person
{
	private:
		int id;
		double gpa;
	public:
		void set_id(int id);
		void set_gpa(double gpa);
		int get_id();
		int get_gpa();
		void show();
		
	/* setters */
	void Student::set_id(int id)
	{
		this->id = id;
	}
	void Student::set_gpa(double gpa)
	{
		this->gpa = gpa;
	}
	
	/* getters */
	int Student::get_id()
	{
		return id;
	}
	int Student::get_gpa()
	{
		return gpa;
	}
	
	/* print data */
	void Student::show()
	{
		cout << "Name: " << name << "\nAge: " << age << "\nID: " << id << "\nGPA: " << gpa << "\n";
	}
}