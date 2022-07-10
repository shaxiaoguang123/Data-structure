#include <iostream>
using namespace std;

class SeqString {
    friend SeqString operator+(const SeqString& s1, const SeqString& s2);
    friend bool operator==(const SeqString& s1, const SeqString& s2);
    friend bool operator!=(const SeqString& s1, const SeqString& s2);
    friend bool operator>(const SeqString& s1, const SeqString& s2);
    friend bool operator>=(const SeqString& s1, const SeqString& s2);
    friend bool operator<(const SeqString& s1, const SeqString& s2);
    friend bool operator<=(const SeqString& s1, const SeqString& s2);
    friend ostream& operator<<(ostream& os, const SeqString& s);

    char* data;
    int len;

   public:
    SeqString(const char* s = "");
    SeqString(const SeqString& other);
    ~SeqString();
    int length() const;
    SeqString& operator=(const SeqString& other);
    SeqString subStr(int start, int num) const;
    void insert(int start, const SeqString& s);
    void remove(int start, int num);
};

int main() {
    SeqString s1("hello");
    SeqString s2("world");
    SeqString s3(s1);
    bool judgment;
    s2 = s1;
    if (s1 == s2)
        judgment = true;
    else
        judgment = false;
    cout << judgment << endl;
    s1.insert(5, " ikun");
    cout << s1 << endl;
    s2 = s1.subStr(0, 90);
    s2.remove(5, 90);
    cout << s2 << endl;
    cout << s1.length() << endl;
    system("pause");
}

SeqString::SeqString(const char* s) {
    for (len = 0; s[len] != '\0'; ++len)
        ;
    data = new char[len + 1];
    for (len = 0; s[len] != '\0'; ++len)
        data[len] = s[len];
    data[len] = '\0';
}

SeqString::SeqString(const SeqString& other) {
    data = new char[other.len + 1];
    len = other.len;
    for (len = 0; other.data[len] != '\0'; ++len)
        data[len] = other.data[len];
    data[len] = '\0';
}

SeqString::~SeqString() {
    delete[] data;
}

int SeqString::length() const {
    return len;
}

SeqString& SeqString::operator=(const SeqString& other) {
    if (this == &other)
        return *this;
    delete[] data;
    data = new char[other.len + 1];
    for (len = 0; other.data[len] != '\0'; ++len)
        data[len] = other.data[len];
    data[len] = '\0';
    return *this;
}

SeqString SeqString::subStr(int start, int num) const {
    SeqString tpl;
    if (start < 0 || start > len - 1) {
        tpl.data = new char[1];
        data[0] = '\0';
        tpl.len = 0;
    } else {
        int end = min(len - 1, start + num - 1);
        tpl.data = new char[end - start + 2];
        int i;
        for (i = 0; i <= end - start; ++i)
            tpl.data[i] = data[start + i];
        tpl.data[i] = '\0';
        tpl.len = end - start + 1;
    }
    return tpl;
}

void SeqString::insert(int start, const SeqString& s) {
    if (start < 0 || start > len)
        return;
    SeqString tpl;
    tpl.len = len + s.len;
    tpl.data = new char[tpl.len + 1];
    int i;
    for (i = 0; i < start; ++i)
        tpl.data[i] = data[i];
    for (i = 0; i < s.len; ++i)
        tpl.data[start + i] = s.data[i];
    for (i = 0; i < len - start; ++i)
        tpl.data[start + s.len + i] = data[start + i];
    tpl.data[tpl.len] = '\0';
    delete[] data;
    *this = tpl;
}

void SeqString::remove(int start, int num) {
    if (start < 0 || start > len)
        return;
    int end = min(start + num, len - 1);
    len -= end - start + 1;
    data[len] = '\0';
}

SeqString operator+(const SeqString& s1, const SeqString& s2) {
    SeqString tpl;
    tpl.len = s1.len + s2.len;
    tpl.data = new char[tpl.len + 1];
    int i;
    for (i = 0; i < s1.len; i++)
        tpl.data[i] = s1.data[i];
    for (i = 0; i < s2.len; i++)
        tpl.data[i] = s2.data[i];
    tpl.data[tpl.len] = '\0';
    return tpl;
}

bool operator==(const SeqString& s1, const SeqString& s2) {
    int i;
    if (s1.len != s2.len)
        return false;
    for (i = 0; i < s1.len; i++)
        if (s1.data[i] != s2.data[i])
            return false;
    return true;
}

bool operator!=(const SeqString& s1, const SeqString& s2) {
    return !(s1 == s2);
}

bool operator>(const SeqString& s1, const SeqString& s2) {
    int i;
    for (i = 0; i < s1.len; i++) {
        if (s1.data[i] > s2.data[i])
            return true;
        else if (s2.data[i] < s1.data[i])
            return false;
    }
    return false;
}

bool operator>=(const SeqString& s1, const SeqString& s2) {
    int i;
    for (i = 0; i < s1.len; i++)
        if (s1.data[i] > s2.data[i] || s1.data[i] == s2.data[i])
            return true;
        else
            return false;
}

bool operator<(const SeqString& s1, const SeqString& s2) {
    return !(s1 >= s2);
}

bool operator<=(const SeqString& s1, const SeqString& s2) {
    return !(s1 > s2);
}

ostream& operator<<(ostream& os, const SeqString& s) {
    os << s.data;
    return os;
}