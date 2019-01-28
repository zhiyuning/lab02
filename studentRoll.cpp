#include <string>
#include <sstream>
#include "studentRoll.h"

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {
  Node *node=new Node;
  Student *ne=new Student(s);
  node->s=ne;
  node->next=NULL;
  if(this->head==NULL){
    head=node;
    tail=node;
  }else{
    tail->next=node;
    tail=node;
  }
}

std::string StudentRoll::toString() const {
  std::ostringstream oss;

  if (head==NULL) {
    oss <<"["
        <<"]";
  }else{
    Node *temp=head;
    oss <<"["
        <<head->s->toString();
    while(temp->next!=NULL){
      temp=temp->next;
      oss <<","<<temp->s->toString();
    }
    oss <<"]";
  }
  return oss.str();
}

StudentRoll::StudentRoll(const StudentRoll &orig) {
  if(orig.head != 0){
    Node *prev=new Node;
    Student *ne=new Student(*orig.head->s);
    prev->s=ne;
    if(orig.head!=orig.tail){
      head=prev;
      for(Node *i=orig.head->next;i->next!=0;i=i->next) {
        Node *temp=new Node;
        Student *ne=new Student(*orig.head->s);
        temp->s=ne;

        prev->next= temp;
        prev=prev->next;
      }
      Node *temp2=new Node;
      Student *ne1=new Student(*orig.tail->s);
      temp2->s=ne1;

      prev->next=temp2;
      tail=temp2;
    }else{
      head = prev;
      tail = prev;
    }
  }else{
    head = 0;
    tail = 0;
  }
//  Node *curr=orig.head;
//  while(curr->next!=NULL){
//    curr=curr->next;
//    insertAtTail(* curr->s);
//  }
//  insertAtTail(* curr->s);
}





StudentRoll::~StudentRoll() {
  Node *nex;
  for(Node *p=head;p!=0;p=nex){
    nex=p->next;
    delete p->s;
    delete p;
  }
  head=NULL;
  tail=NULL;
}

StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this){
    return (*this);
  }
  if(right.head!=NULL){
    Node *prev=new Node;
    Student *ne=new Student(*right.head->s);
    prev->s=ne;
    if(right.head!=right.tail){
      head=prev;
      for(Node *i=right.head->next;i->next!=0;i=i->next) {
        Node *temp=new Node;
        Student *ne=new Student(*right.head->s);
        temp->s=ne;

        prev->next=temp;
        prev=prev->next;
      }
      Node *temp2=new Node;
      Student *ne1=new Student(*right.tail->s);
      temp2->s=ne1;

      prev->next=temp2;
      tail=temp2;
    }else{
      head = prev;
      tail = prev;
    }
  }else{
    head = 0;
    tail = 0;
  }
  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this);

}
