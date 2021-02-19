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
        std::cout << "Year을 입력하십시오\n";
        std::cin >> yearin;
        std::cout << "Month을 입력하십시오\n";
        std::cin >> monthin;
        std::cout << "Day를 입력하십시오\n";
        std::cin >> datein;

        Date_.SetDate(yearin, monthin, datein);
        Date_.ShowDate();

        std::cout << "Day를 더하려면 1, Month를 더하려면 2, Year을 더하려면 3을 누르시오.\n";
        int dmy_choice_num;
        std::cin >> dmy_choice_num;
        switch (dmy_choice_num)
        {
        case 1:
            int date_inc;
            std::cout << "증가시킬 Day를 입력하시시오.";
            std::cin >> date_inc;
            Date_.AddDay(date_inc);
            break;
        case 2:
            int month_inc;
            std::cout << "증가시킬 Month를 입력하시시오.";
            std::cin >> month_inc;
            Date_.AddMonth(month_inc);
            break;
        case 3:
            int year_inc;
            std::cout << "증가시킬 Year을 입력하시시오.";
            std::cin >> year_inc;
            Date_.AddYear(year_inc);
            break;
        default:
            std::cout << "잘못된 입력입니다.";
        }
        Date_.ShowDate();

    }

    return 0;
}