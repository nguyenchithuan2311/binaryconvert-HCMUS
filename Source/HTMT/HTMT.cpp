#include <iostream>
#include<string>
#include<math.h>
#include<regex>
#include<Windows.h>
#include<iomanip>
using namespace std;
string intToBinary(int n)
{
    string r;
    while (n != 0) { r = (n % 2 == 0 ? "0" : "1") + r; n /= 2; }
    return r;
}
string dec_to_bin(float number)
{
    string bin = "";
    while (number > 0)
    {
        number = number * 2;
        if (number >= 1)
        {
            bin = bin + "1";
            number--;
        }
        else {
            bin = bin + "0";
        }
    }
    return bin;
}
string to_IEEE75_32bit(float number)
{
    // get the sign bit
    string sign_bit;
    if (number > 0)
    {
        sign_bit = "0";
    }
    else {
        sign_bit = "1";
    }
    int num = abs(number);
    string exponent;
    exponent = intToBinary((intToBinary(num)).size() + 127 - 1);
    while (exponent.size() < 8)
    {
        exponent = "0" + exponent;
    }
    string decimal_part = dec_to_bin(abs(number) - num);
    string mantisa;
    string pos = intToBinary(num) + decimal_part;
    mantisa = string(pos.begin() + 1, pos.end());
    while (mantisa.size() < 23)
    {
        mantisa = mantisa + "0";
    }
    string iEE75 = sign_bit + " " + exponent + " " + mantisa;
    return iEE75;
}
string to_IEEE75_64bit(float number)
{
    // get the sign bit
    string sign_bit;
    if (number > 0)
    {
        sign_bit = "0";
    }
    else {
        sign_bit = "1";
    }
    int num = abs(number);
    string exponent;
    exponent = intToBinary((intToBinary(num)).size() + 1023 - 1);
    while (exponent.size() < 11)
    {
        exponent = "0" + exponent;
    }
    string decimal_part = dec_to_bin(abs(number) - num);
    string mantisa;
    string pos = intToBinary(num) + decimal_part;
    mantisa = string(pos.begin() + 1, pos.end());
    while (mantisa.size() < 52)
    {
        mantisa = mantisa + "0";
    }
    string iEE75 = sign_bit + " " + exponent + " " + mantisa;
    return iEE75;
}
string unsign_interger(float num)
{
    int a;
    if (num - int(num) >= 0.5)
    {
        a = int(num) + 1;
    }
    else {
        a = int(num);
    }
    cout << "chon so bit bieu dien" << endl;
    cout << "1: 8bit 2: 16 bit 3:32bit" << endl;
    int choice;
    do {
        cin >> choice;
        if (choice > 3)
        {
            cout << " so khong hop le. Vui long nhap lai ";
        }
    } while (choice > 3);
    if (choice == 1)
    {
        string result = intToBinary(a);
        while (result.size() < 8)
        {
            result = "0" + result;
        }

        if (result.size() > 8)
        {
            result = result.substr(0, 8);
        }
        return result;
    }
    if (choice == 2)
    {
        string result = intToBinary(a);
        while (result.size() < 16)
        {
            result = "0" + result;
        }
        if (result.size() > 16)
        {
            result = result.substr(0, 16);
        }
        return result;
    }
    if (choice == 3)
    {
        string result = intToBinary(a);
        while (result.size() < 32)
        {
            result = "0" + result;
        }
        if (result.size() > 32)
        {
            result = result.substr(0, 32);
        }
        return result;
    }
}
string sign_interger(float num)
{
    string positive = "0";
    string negative = "1";
    string result;
    if (num > 0)
    {
        int a;
        if (num - int(num) >= 0.5)
        {
            a = int(num) + 1;
        }
        else {
            a = int(num);
        }
        cout << "chon so bit bieu dien" << endl;
        cout << "1: 8bit 2: 16 bit 3:32bit" << endl;
        int choice;
        do {
            cin >> choice;
            if (choice > 3)
            {
                cout << " so khong hop le. Vui long nhap lai ";
            }
        } while (choice > 3);
        if (choice == 1)
        {
            result = intToBinary(a);
            while (result.size() < 7)
            {
                result = "0" + result;
            }
            result = positive + result;
            if (result.size() > 8)
            {
                result = result.substr(0, 8);
            }
            cout << "Signed: ";
            return result;
        }
        if (choice == 2)
        {
            result = intToBinary(a);
            while (result.size() < 15)
            {
                result = "0" + result;
            }
            result = positive + result;
            if (result.size() > 16)
            {
                result = result.substr(0, 16);
            }
            cout << "Signed: ";
            return result;
        }
        if (choice == 3)
        {
            result = intToBinary(a);
            while (result.size() < 31)
            {
                result = "0" + result;
            }
            result = positive + result;
            if (result.size() > 32)
            {
                result = result.substr(0, 32);
            }
        }
        cout << "Signed: ";
        return result;
    }
    else if (num < 0)
    {
        int b;
        if (num - int(num) <= -0.5)
        {
            b = -int(num) + 1;
        }
        else {
            b = -int(num);
        }
        cout << "chon so bit bieu dien am" << endl;
        cout << "1:8bit  2:16 bit  3:32bit" << endl;
        int choice;
        do {
            cin >> choice;
            if (choice > 3)
            {
                cout << " so khong hop le. Vui long nhap lai ";
            }
        } while (choice > 3);
        int num = abs(b);
        if (choice == 1)
        {
            result = intToBinary(num);
            while (result.size() < 7)
            {
                result = "0" + result;
            }
            for (int i = 0; i < result.size(); i++)
            {
                if (result[i] == '0')
                {
                    result[i] = '1';
                }
                else {
                    result[i] = '0';
                }
            }
            for (int i = result.size() - 1; i >= 0; i--)
            {
                if (result[i] == '0')
                {
                    result[i] = '1';
                    break;
                }
                else if (result[i] == '1')
                {
                    result[i] = '0';
                }
            }
            result = result.substr(0, 7);
            result = negative + result;
            cout << "Signed: ";
            return result;
        }
        if (choice == 2)
        {
            result = intToBinary(num);
            while (result.size() < 15)
            {
                result = "0" + result;
            }
            for (int i = 0; i < result.size(); i++)
            {
                if (result[i] == '0')
                {
                    result[i] = '1';
                }
                else {
                    result[i] = '0';
                }
            }
            for (int i = result.size() - 1; i >= 0; i--)
            {
                if (result[i] == '0')
                {
                    result[i] = '1';
                    break;
                }
                else if (result[i] == '1')
                {
                    result[i] = '0';
                }
            }
            result = result.substr(0, 15);
            result = negative + result;
            cout << "Signed: ";
            return result;
        }
        if (choice == 3)
        {
            result = intToBinary(num);
            while (result.size() < 31)
            {
                result = "0" + result;
            }
            for (int i = 0; i < result.size(); i++)
            {
                if (result[i] == '0')
                {
                    result[i] = '1';
                }
                else {
                    result[i] = '0';
                }
            }
            for (int i = result.size() - 1; i >= 0; i--)
            {
                if (result[i] == '0')
                {
                    result[i] = '1';
                    break;
                }
                else if (result[i] == '1')
                {
                    result[i] = '0';
                }
            }
            result = result.substr(0, 31);
            result = negative + result;
            cout << "Signed: ";
            return result;
        }
    }
}
long double unsignedBinToDec(string binaryNumber)
{
	long double decimal = 0;
		for (int i = 0; i < binaryNumber.size(); i = i + 1) {
			string temp;
			temp = temp + binaryNumber[i];
			decimal = decimal + stoll(temp) * pow(2, binaryNumber.size() - (i+1));
		}
	return decimal;
}
bool checksize(int size) {
	if (size != 8 && size != 16 && size != 32 && size != 64)
	{
		return false;
	}
	else {
		return true;
	}
}
string handleSpaceInputString(string binary) {
	while (binary.find(' ') != -1) {
		binary.replace(binary.find(' '), 1, "");
	}
	return binary;
}
string handlingMissingInputString(string binary,int size) {
	string str;
	if (binary.size() < 16 && size != 8) {
		for (int i = 0; i < 16 - binary.size(); i = i + 1) {
			str = str + "0";
		}
	}
	str = str + binary;
	return str;
}
string bitIsland(string binary) {
	string temp;
	for (int i = 1; i < binary.size(); i = i + 1) {
		temp = temp + binary[i];
	}
	for (int i = 0; i < temp.size(); i = i + 1) {
		if (temp[i] == '1') {
			temp[i] = '0';
		}
		else {
			temp[i] = '1';
		}
	}
	return temp;
}
long double BitFloatingPoint32(string binary) {
	string temp;
	string Sign;
	string Exponent;
	string Mantissa;
	if (binary.size() < 32) {
		for (int i = 0; i < 32 - binary.size(); i = i + 1) {
			temp = temp + '0';
		}
	}
	temp = temp + binary;
	Sign = temp[0];
	long double sum = 0;
	for (int i = 1; i <= 8; i = i + 1) {
		Exponent = Exponent + temp[i];
	}
	for (int i = 9; i <= 31; i = i + 1) {
		Mantissa = Mantissa + temp[i];
	}
	float a = 1;
	long long f = pow(-1, stoi(Sign));
	int x = unsignedBinToDec(Exponent) - 127;
	long double m ; 
	if (x > 0) {
		m = pow(2, x);
	}
	else {
		m = 1 / pow(2, abs(x));
	}
	for (int i = 0; i < 23; i = i + 1) {
		string h = "";
		h = h + Mantissa[i];
		a = a + stof(h) * 1.0 * pow(2, -i - 1);
	}
	sum = f * m * a;
	return sum;
}
long double BitFloatingPoint64(string binary) {
	string temp;
	string Sign;
	string Exponent;
	string Mantissa;
	if (binary.size() < 64) {
		for (int i = 0; i < 64 - binary.size(); i = i + 1) {
			temp = temp + '0';
		}
	}
	temp = temp + binary;
	Sign = temp[0];
	long double sum = 0;
	for (int i = 1; i <= 11; i = i + 1) {
		Exponent = Exponent + temp[i];
	}
	for (int i = 12; i <= 63; i = i + 1) {
		Mantissa = Mantissa + temp[i];
	}
	double a = 1;
	long long f = pow(-1, stoi(Sign));
	long double x = unsignedBinToDec(Exponent) - 1023;
	long double m=0;
	if (x > 0) {
		m = powl(2, x);
	}
	else {
		m = 1 / powl(2, abs(x));
	}
	for (int i = 0; i < 52; i = i + 1) {
		string h = "";
		h = h + Mantissa[i];
		a = a + stof(h) * 1.0 * pow(2, -i - 1);
	}
	sum = f * m * a;
	return sum;
}
int main()
{
    int choose;
    while (true) {
        cout << "1.Ban muon doi binary sang demacial" << endl;
        cout << "2.Ban muon doi demacial sang binary" << endl;
        cout << "3.De thoat khoi chuong trinh" << endl;
        cout << "Nhap lua chon: ";
        cin >> choose;
        if (choose == 1) {
            double value;
            cout << "Ban hay nhap so thap phan muon doi" << endl;
            cin >> value;
            cout << "Floating point 32 bit: ";
            cout << to_IEEE75_32bit(value);
            cout << endl;
            cout << "Floating point 64 bit: ";
            cout << to_IEEE75_64bit(value);
            cout << endl;
            cout << sign_interger(value)<<endl;
            cout << endl;
            cout << endl;
        }
        else if (choose == 2) {
            int size = 0;
            cout << "Ban muon nhap bao nhieu byte(8,16,32 hay 64): ";
            cin >> size;
            while (true) {
                if (checksize(size) == false)
                {
                    cout << "Ban hay nhap lai sai size: ";
                    cin >> size;
                }
                else {
                    break;
                }
            }
            cout << "Nhap chuoi nhi phan (co the nhap dau cach vd(0101 000)): ";
            string n;
            getline(cin, n);
            getline(cin, n);
            n = handleSpaceInputString(n);
            string str;
            str = handlingMissingInputString(n, size);
            regex regex("\\b[0-1]+\\b");
            long long a = 0;
            bool result = regex_match(n, regex);
            while (true) {
                if (result == false) {
                    cout << "Nhap lai chuoi nhi phan: ";
                    cin >> n;
                    result = regex_match(n, regex);
                }
                else {
                    break;
                }
            }
            if (result == true&&size==32) {
                a = unsignedBinToDec(str);
                cout << "Unsigned: " << a << endl;
            }
            if (result == true && str[0] == '1' && size == 32) {
                string temp = bitIsland(str);
                cout << "signed: " << "-" << unsignedBinToDec(temp) + 1 << endl;
            }
            else {
                cout << "signed: " << a << endl;
            }
            if (size == 32) {
                cout << "Floating point 32 bit: " << BitFloatingPoint32(n)<<endl;
                cout << endl;
                cout << endl;
            }
            else if (size == 64) {
                cout << "Floating point 64 bit: " << BitFloatingPoint64(n)<<endl;
                cout << endl;
                cout << endl;
            }
        }
        else if (choose == 3) {
            break;
        }
        else {
            cout << "Nhap lai lua chon: ";
            cin >> choose;
        }
    }
    cin.get();
}