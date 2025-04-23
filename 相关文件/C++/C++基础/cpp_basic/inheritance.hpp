#ifndef INHERITANCE_HPP
#define INHERITANCE_HPP

#include <string>
#include <vector>

struct _List_node_bse {
    _List_node_bse *_M_next;
    _List_node_bse *_M_prev;
};

template<typename _Tp>
struct _List_node: public _List_node_bse {
    _Tp _M_data;
};

class Shape {
    public:
        virtual void draw () const = 0; // pure virtual
        virtual void error (const std::string &msg); // impure virtual
        int objectID () const; // non-virtual
};

class CDocument {
    public:
        void OnFileOpen ();
        virtual void Serialize ();
};
void CDocument::OnFileOpen () {
    Serialize();
}

class CMyDoc: public CDocument {
    public:
        virtual void Serialize (); // template method设计模式
};

void test () {
    CMyDoc myDoc;
    myDoc.OnFileOpen();
}

class Subject;

class Observer {
    public:
        virtual void update (Subject *sub, int value) = 0;
};

class Subject {
        int m_value;
        std::vector<Observer *> m_views;
    public:
        void attach (Observer *obs) {
            m_views.push_back(obs);
        };
        void set_val (int value) {
            m_value = value;
            notify();
        };
        void notify () {
            for (int i = 0 ; i < m_views.size() ; ++i) {
                m_views[i]->update(this, m_value);
            }
        };
};

class Component {
        int value;
    public:
        Component (int val) { value = val; }
        virtual void add (Component *) {}
};

class Primitive: public Component {
    public:
        Primitive (int val)
            : Component(val) {}
};

class Composite: public Component {
        std::vector<Component *> c;
    public:
        Composite (int val)
            : Component(val) {}
        void add (Component *elem) {
            c.push_back(elem);
        }
};

class Image {
    public:
        static Image *findAndClone ();
    protected:
        virtual Image *clone () = 0; // 纯虚函数
        static void addPrototype (Image *p);
    private:
        static std::vector<Image *> prototype;
};

class LandSatImage: Image {
    public:
        Image *clone () { return new LandSatImage(1); };
    protected:
        LandSatImage (int i) { id = count++; };
    private:
        static LandSatImage LSAT;
        LandSatImage () { addPrototype(this); };
        int id;
        static int count;
};

#endif //INHERITANCE_HPP
