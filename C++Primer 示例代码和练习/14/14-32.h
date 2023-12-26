
class StrBlobPtr;
class StrBlobPtr_pointer
{
private:
    StrBlobPtr *pointer = nullptr;

public:
    StrBlobPtr_pointer() = default;
    StrBlobPtr_pointer(StrBlobPtr *p) : pointer(p) {}

    StrBlobPtr &operator*();
    StrBlobPtr *operator->();
};
