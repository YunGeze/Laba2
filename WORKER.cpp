#include "WORKER.h"

WORKER::WORKER()
{
    this->year = 0;
    this->fio = "";
    this->status = "";


}

WORKER::WORKER(const WORKER& obj)
{
    this->fio = obj.fio;
    this->status = obj.status;
    this->year = obj.year;

}

WORKER::WORKER(std::string fio, std::string status, int year)
{

    this->fio = fio;
    this->status = status;
    this->year = year;

}

int WORKER::getYear()
{
    return year;

}

std::string WORKER::getFio()
{
    return std::string(fio);
}

std::string WORKER::getStatus()
{
    return std::string(status);
}

void WORKER::setYear(int year)
{
    this->year=year;
}

void WORKER::setFio(std::string fio)
{
    this->fio = fio;
}

void WORKER::setStatus(std::string status)
{
    this->status = status;
}

WORKER& WORKER::operator=(const WORKER& obj)
{
    this->fio = obj.fio;
    this->status = obj.status;
    this->year = obj.year;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const WORKER& w)
{
    
    out <<"FIO: " << w.fio << "\n";
    out << "Status: " << w.status << "\n";
    out << "Start work: " << w.year << "\n";
    
    
    return out;
}

bool operator<(const WORKER& ob1, const WORKER& ob2)
{
    return ob1.fio<ob2.fio?true:false;
}

bool operator>(const WORKER& ob1, const WORKER& ob2)
{
    return ob1.fio > ob2.fio ? true : false;
}

bool operator==(const WORKER& ob1, const WORKER& ob2)
{
    return  ob1.fio == ob2.fio ? true : false;
}

bool operator!=(const WORKER& ob1, const WORKER& ob2)
{
    return ob1.fio != ob2.fio ? true : false;
}
