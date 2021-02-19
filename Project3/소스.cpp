#include <iostream>

class Date {
    int year_;
    int month_;
    int date_;

public:
    void SetDate(int year, int month, int date)
    {
        year_ = year;
        month_ = month;
        date_ = date;



    }
    void AddDay(int inc)
    {
        date_ += inc;
        if (((month_ == 2) && (date_ > 28)))
        {
            AddMonth(1);
            date_ -= 28;
            AddDay(0);
        }
        if (((month_ == 1) || (month_ == 3) || (month_ == 5) || (month_ == 7) || (month_ == 8) || (month_ == 10) || (month_ == 12)) && (date_ > 31))
        {
            AddMonth(1);
            date_ -= 31;
            AddDay(0);
        }
        if (((month_ == 4) || (month_ == 6) || (month_ == 9) || (month_ == 11)) && (date_ > 30))
        {
            AddMonth(1);
            date_ -= 30;
            AddDay(0);
        }
    }
    void AddMonth(int inc)
    {
        month_ += inc;
        if (month_ > 12)
        {
            AddYear(1);
            month_ -= 12;
            AddMonth(0);
        }
    }
    void AddYear(int inc)
    {
        year_ += inc;
    }

    void ShowDate()
    {
        std::cout << "Date:" << date_ << std::endl;
        std::cout << "Month:" << month_ << std::endl;
        std::cout << "Year:" << year_ << std::endl;
    }
};

int main()
{
    while (1)
    {
        Date Date_;
        int yearin, monthin, datein;
        std::cout << "Year�� �Է��Ͻʽÿ�\n";
        std::cin >> yearin;
        std::cout << "Month�� �Է��Ͻʽÿ�\n";
        std::cin >> monthin;
        std::cout << "Day�� �Է��Ͻʽÿ�\n";
        std::cin >> datein;

        Date_.SetDate(yearin, monthin, datein);
        Date_.ShowDate();

        std::cout << "Day�� ���Ϸ��� 1, Month�� ���Ϸ��� 2, Year�� ���Ϸ��� 3�� �����ÿ�.\n";
        int dmy_choice_num;
        std::cin >> dmy_choice_num;
        switch (dmy_choice_num)
        {
        case 1:
            int date_inc;
            std::cout << "������ų Day�� �Է��Ͻýÿ�.";
            std::cin >> date_inc;
            Date_.AddDay(date_inc);
            break;
        case 2:
            int month_inc;
            std::cout << "������ų Month�� �Է��Ͻýÿ�.";
            std::cin >> month_inc;
            Date_.AddMonth(month_inc);
            break;
        case 3:
            int year_inc;
            std::cout << "������ų Year�� �Է��Ͻýÿ�.";
            std::cin >> year_inc;
            Date_.AddYear(year_inc);
            break;
        default:
            std::cout << "�߸��� �Է��Դϴ�.";
        }
        Date_.ShowDate();

    }

    return 0;
}