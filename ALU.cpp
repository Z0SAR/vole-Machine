#include "ALU.h"
string ALU::HexToBinary (const string& hex)
{
    unordered_map<char , string>  maphtob =
    {
        {'0', "0000"}, {'1', "0001"}, {'2', "0010"}, {'3', "0011"},
        {'4', "0100"}, {'5', "0101"}, {'6', "0110"}, {'7', "0111"},
        {'8', "1000"}, {'9', "1001"}, {'A', "1010"}, {'B', "1011"},
        {'C', "1100"}, {'D', "1101"}, {'E', "1110"}, {'F', "1111"}
    };
    string binary = "";
    for (char x : hex)
    {
        if (islower(x)) {x = toupper(x);}
        binary += maphtob[x];
    }
    return binary;
}
int ALU::binaryToDecimal(const string& binary)
{
    int decimal = 0 ;
    int base = 1;
    for (int i = binary.length() - 1; i >= 0; i--)
    {
        if (binary[i] == '1') {decimal += base;}
        base *= 2;
    }
    return decimal;
}
string ALU::decimalToBinary(int decimal)
{
    string binary = "";
    if(decimal==0) {
        return "0000";
    }
    while (decimal > 0)
    {
        if (decimal % 2 == 0) {binary = "0" + binary;}
        else {binary = "1" + binary;}
        decimal /= 2;
    }
    while(binary.size() % 4 != 0)
    {
        binary = "0" + binary;
    }
    return binary;
}
string ALU::binaryToHex(const string& binary)
{
    unordered_map<string, char> mapbtoh =
    {
        {"0000", '0'}, {"0001", '1'}, {"0010", '2'}, {"0011", '3'},
        {"0100", '4'}, {"0101", '5'}, {"0110", '6'}, {"0111", '7'},
        {"1000", '8'}, {"1001", '9'}, {"1010", 'A'}, {"1011", 'B'},
        {"1100", 'C'}, {"1101", 'D'}, {"1110", 'E'}, {"1111", 'F'}
    };
    string hex = "";
    for (int i = 0 ; i < binary.size(); i += 4)
    {
        string digits = binary.substr(i, 4);
        hex += mapbtoh[digits];
    }
    return hex;
}
int ALU::hexToDec(const string& hex)
{
    return binaryToDecimal(HexToBinary(hex));
}
string ALU::DecTohex(const int& Dec)
{
    return binaryToHex(decimalToBinary(Dec));
}
string ALU::twosComplement(string& bin)
{
    reverse(bin.begin(), bin.end());
    size_t found = bin.find('1');
    if (found != string::npos)
    {
        for (size_t i = found + 1; i < bin.length(); i++)
        {
            if(bin[i] == '1') {bin[i] == '0';}
            else  { bin[i] == '1';}
        }

    }
    reverse (bin.begin(), bin.end());
    return bin;
}
void ALU::add(int idx1, int idx2, int idx3, Register& cpuRegister) {
    int carry = 0;
    string result;
    string hex1 = cpuRegister.getCell(idx1);
    string hex2 = cpuRegister.getCell(idx2);
    string valueBin1 = HexToBinary(hex1);
    string valueBin2 = HexToBinary(hex2);
    if (valueBin1.length() < 8) {valueBin1 = string(8 - valueBin1.length(), '0') + valueBin1;}
    if (valueBin2.length() < 8) {valueBin2 = string(8 - valueBin2.length(), '0') + valueBin2;}


    bool isNegative1 = (valueBin1[0] == '1');
    bool isNegative2 = (valueBin2[0] == '1');

    if (isNegative1) {valueBin1 = twosComplement(valueBin1);}
    if (isNegative2) {valueBin2 = twosComplement(valueBin2);}

    for (int i = 8 - 1; i >= 0; i--)
    {
        int bit_num1 = valueBin1[i] - '0';
        int bit_num2 = valueBin2[i] - '0';
        int sum = bit_num1 + bit_num2 + carry;
        int result_bit = sum % 2;
        carry = sum / 2;
        result = to_string(result_bit) + result;
    }
    if (carry) {result = twosComplement(result);}
    result = binaryToHex(result);
    cpuRegister.setCell(idx3, result);
}

string ALU::floatToBinary(float number)
{
    if (number == 0.0f) {
        return "00000000";
    }

    int sign = (number < 0) ? 1 : 0;
    if (sign) number = -number;

    int exponent = 0;
    while (number >= 2.0f)
    {
        number /= 2.0f;
        exponent++;
    }
    while (number < 1.0f)
    {
        number *= 2.0f;
        exponent--;
    }

    int biasedExponent = exponent + 4;
    // if (biasedExponent < 0 || biasedExponent >= 7)
    // {
    //     throw out_of_range("Exponent is out of range for 3-bit representation");
    // }

    number -= 1.0f;
    vector<int> mantissa(4, 0);
    for (int i = 0; i < 4; i++)
    {
        number *= 2.0f;
        if (number >= 1.0f)
        {
            mantissa[i] = 1;
            number -= 1.0f;
        }
    }

    string mantissaStr;
    for (int x : mantissa)
    {
        mantissaStr += to_string(x);
    }

    string result = to_string(sign) + bitset<3>(biasedExponent).to_string() + mantissaStr;
    return result;
}

float ALU::binaryToFloat(string &binary)
{
    if (binary.size() != 8)
    {
        if (binary.size() > 8) {throw invalid_argument("Binary string must be exactly 8 bits");}
        else
        { while (binary.size() < 8) {binary = '0' + binary;}}
    }

    int sign = binary[0] - '0';
    bitset<3> exponentBits(binary.substr(1, 3));
    int biasedExponent = (int)(exponentBits.to_ulong());
    int exponent = biasedExponent - 4;

    bitset<4> mantissaBits(binary.substr(4, 4));
    float mantissa = 1.0f;

    for (int i = 0; i < 4; i++)
    {
        if (mantissaBits[i] == 1)
        {
            mantissa += pow(2, -(i + 1));
        }
    }

    float result = mantissa * pow(2, exponent);
    if (sign == 1) result = -result;

    return result;
}

void ALU::addfloat(int idx1, int idx2, int idx3, Register &cpuRegister)
{
    string hex1 = cpuRegister.getCell(idx1);
    string hex2 = cpuRegister.getCell(idx2);

    string valueBin1 = HexToBinary(hex1);
    string valueBin2 = HexToBinary(hex2);

    if (valueBin1.size() > 8 || valueBin2.size() > 8)
    {
        throw overflow_error("Binary representation exceeds 8 bits");
    }

    while (valueBin1.size() < 8) {valueBin1 = '0' + valueBin1;}
    while (valueBin2.size() < 8) {valueBin2 = '0' + valueBin2;}

    float num1 = binaryToFloat(valueBin1);
    float num2 = binaryToFloat(valueBin2);
    float addTwoNum = num1 + num2;

    try
    {
        string finalBinary = floatToBinary(addTwoNum);
        string finalHex = binaryToHex(finalBinary);
        cpuRegister.setCell(idx3, finalHex);
    }
    catch (const out_of_range &e)
    {
        cerr << "Error during addition: " << e.what() << endl;
        throw;
    }
}