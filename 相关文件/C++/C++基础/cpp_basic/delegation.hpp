#ifndef DELEGATION_HPP
#define DELEGATION_HPP

class StringRep;

class String {
    public:
        String ();
        String (const char *s);
        String (const String &s);
        ~String ();
    private:
        StringRep *rep; // pimpl (Handle/Body)
};

class StringRep {
        friend class String;
        StringRep (const char *s);
        ~StringRep ();
};

#endif //DELEGATION_HPP
