#include <bits/stdc++.h>

using namespace std;

constexpr unsigned ch2int(char ch) noexcept {
    assert(ch >= '0' && ch <= '9');
    return ch - '0';
}

constexpr char int2ch(unsigned i) noexcept {
    assert(i >= 0 && i <= 9);
    return i + '0';
}

// This is a lazy unsigned-big-number implementation by me
class UBigInteger final {
public:

    std::string const& str() const noexcept {
        return mData;
    }

    size_t length() const noexcept {
        return mData.size();
    }

    unsigned digitAt(size_t index) const noexcept {
        return ch2int(mData[index]);
    }

    UBigInteger& operator+=(UBigInteger const& other) {
        std::string res;
        unsigned carry = 0;

        auto const max_len = std::max(length(), other.length());

        for (size_t i = 0; i < max_len; ++i) {
            unsigned this_dig = 0;
            if (i < length())
                this_dig = digitAt(length() - i - 1);

            unsigned other_dig = 0;
            if (i < other.length())
                other_dig = other.digitAt(other.length() - i - 1);

            unsigned const sum = this_dig + other_dig + carry;
            carry = sum / 10;
            res.push_back(int2ch(sum % 10));
        }

        while (carry)
        {
            res.push_back(int2ch(carry % 10));
            carry /= 10;
        }
        std::reverse(res.begin(), res.end());
        mData = res;
        return *this;
    }

    UBigInteger& operator*=(int const other) {
        auto const other_int = std::to_string(other);
        std::vector<std::string> to_add;
        for (auto bottom = other_int.crbegin(); bottom != other_int.crend(); ++bottom) {
            unsigned carry = 0;
            std::string res;
            for (auto top = mData.crbegin(); top != mData.crend(); ++top) {
                int mult = ch2int(*bottom) * ch2int(*top) + carry;
                carry = mult / 10;
                res.push_back(int2ch(mult % 10));
            }
            while (carry)
            {
                res.push_back(int2ch(carry % 10));
                carry /= 10;
            }
            std::reverse(res.begin(), res.end());
            res.resize(res.size() + (bottom - other_int.crbegin()), '0');
            to_add.push_back(std::move(res));
        }
        mData = "0";
        for (auto& str : to_add) {
            (*this) += UBigInteger(std::move(str));
        }

        return *this;
    }

    explicit UBigInteger(unsigned i)
        : mData(std::to_string(i))
    {}

    explicit UBigInteger(std::string data)
        : mData(std::move(data))
    {
        for (auto ch : mData)
            if (!isdigit((unsigned char)ch))
                throw std::domain_error{ "String not a number" };
    }

private:
    std::string mData;
};

// Complete the extraLongFactorials function below.
void extraLongFactorials(int n) {
    UBigInteger res(1);
    for (int i = 2; i <= n; ++i) {
        res *= i;
    }
    printf("%s\n", res.str().c_str());
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    extraLongFactorials(n);

    return 0;
}
