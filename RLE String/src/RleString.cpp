#include "RleString.h"

// Constructor to initialize an empty RleString
RleString::RleString()
{
    // head and tail pointers are set to null
    head = nullptr;
    tail = nullptr;
}

// Function to push a symbol and its count to the end of the string
void RleString::push_back(const char symbol,const size_t counter)
{
    // Create a new node with the symbol and count
    Node* newNode = new Node(symbol,counter);

    // If the list is empty, set head and tail to the new node
    if (head == nullptr)
    {
        head = tail = newNode;
        return;
    }

    // Add the new node to the end of the list
    tail->next = newNode;
    tail = newNode;
}

void RleString::copyFrom(const RleString &other)
{
    
    Node *itterator = other.head;

    while (itterator)
    {
        push_back(itterator->symbol,itterator->count);
        itterator = itterator->next;
    }
}

void RleString::free()
{
    
    Node *itterator = head;
    while (itterator)
    {
        Node *toDelete = itterator; 
        toDelete= nullptr;
        itterator = itterator->next; 
        delete toDelete; 
    }
    

    head = tail = nullptr;
    
}


RleString:: RleString(const std::string& str): head(nullptr), tail(nullptr)
{
    if (str.size()==0)
    {
        this->head= nullptr;
        this->tail= nullptr;
        
    }else 
    {
    
    unsigned counter = 1;  
    char symbol = str[0];
    
    if(str.size() ==1)
    {
        push_back(symbol,1);
        return;
    }

    for (int i = 1; i < str.size(); i++)
    {
        if (str[i] != str[i-1])
        {
            push_back(str[i-1],counter);
            counter = 1;
           if (i== str.size()-1)
            {
                push_back(str[i],counter);
            }
        } 
        else if (i == str.size()-1)
            {
                counter++;
                push_back(str[i],counter);
            }
        else counter++;

    }   
    }
    
}

RleString:: RleString(const RleString& other)  : head(nullptr), tail(nullptr)
{
    copyFrom(other);
}

RleString& RleString:: operator=(const RleString& other)
{
    if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

RleString:: ~RleString()
{   
    free();
}

std::string RleString::toString() const
{
    std:: string result = "";
    Node* itterator = head;
    while (itterator)
    {
        for (size_t i = 0; i < itterator->count; i++)
        {
            result+=itterator->symbol;
        }
        itterator = itterator->next;
        
    }
    
    return result;
}

bool RleString::operator==(const RleString& other) const
{
    
    Node* itterator = this->head;
    Node* itterator2 = other.head;
    if (this->size() != other.size())
    {
        return false;
    }
    
    while (itterator && itterator2)
    {
        if (itterator->symbol != itterator2->symbol)
        {
            return false;
        }

        itterator= itterator->next;
        itterator2= itterator2->next;
    }
    
    return true;
    
}

bool RleString::operator==(const std::string& str) const
{
    return this->toString() == str; 
}

size_t RleString::size() const noexcept
{
    size_t size = 0; 
    Node *itterator = head;
    
    while (itterator != nullptr)
    {
        size += itterator->count;
        itterator = itterator->next;
    }
   
    return size;
}

void RleString::insertAt(size_t index, char value)
{
    if(index > this->size())
    {
        throw std:: out_of_range("");
    }
    string a = this->toString();
    a.insert(index,1,value);
    RleString result = a;
    
    free();
    copyFrom(result);
}

void RleString:: removeAt(size_t index)
{
     if(index >= this->size())
    {
        throw std:: out_of_range("");
    }

    string current = this->toString();
    current.erase(index,1);
    RleString result = current;
    free();
    copyFrom(result);
}

void RleString::reverse()
{
    Node* current = this->head;
    Node* prev = nullptr;
    Node* next = nullptr;

   while (current)
   {
        next = current->next;
        current->next= prev;
        prev = current;
        current = next;
   }

   head = prev;
}

bool RleString::contains(const RleString& rle) const
{
    if(rle.size()<1) return true;
    Node* iterator1 = this->head;
    Node* iterator2 = rle.head;

    while (iterator1 && iterator2)
    {
        if(iterator1->symbol==iterator2->symbol)
        {
            iterator1=iterator1->next;
            iterator2 = iterator2->next;
            if(iterator2->next==nullptr && iterator1->symbol==iterator2->symbol)
            {
                return true;
            }
        }else if (iterator1->symbol != iterator2->symbol)
        {
            iterator1 = iterator1->next;
            iterator2= rle.head;
        }
    }
    

    return false;
    
}
