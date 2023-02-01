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

// Function to copy data from another RleString
void RleString::copyFrom(const RleString &other)
{
    // An iterator to traverse through the other RleString
    Node *itterator = other.head;

    // Push each symbol and count to the end of this RleString
    while (itterator)
    {
        push_back(itterator->symbol,itterator->count);
        itterator = itterator->next;
    }
}

// Function to free memory allocated by the list
void RleString::free()
{
    
    // An iterator to traverse through the list
    Node *itterator = head;
    // Delete each node in the list
    while (itterator)
    {
        Node *toDelete = itterator; 
        toDelete= nullptr;
        itterator = itterator->next; 
        delete toDelete; 
    }
    
    // Set head and tail to null
    head = tail = nullptr;
    
}

// constructor for the RleString class
RleString:: RleString(const std::string& str): head(nullptr), tail(nullptr)
{
	
    // If the input string is empty, set head and tail to nullptr
    if (str.size()==0)
    {
        this->head= nullptr;
        this->tail= nullptr;
        
    }else 
    {
	    
    // initialize counter and symbol variables
    unsigned counter = 1;  
    char symbol = str[0];
	    
    // if the input string has only one character, call push_back with the symbol and counter
    if(str.size() ==1)
    {
        push_back(symbol,1);
        return;
    }
	    
    // loop through the input string starting from the second character
    for (int i = 1; i < str.size(); i++)
    {
	// if the current character is different from the previous one, call push_back with the symbol and counter
        if (str[i] != str[i-1])
        {
            push_back(str[i-1],counter);
            counter = 1;
	   // if we have reached the end of the string, call push_back with the symbol and counter
           if (i== str.size()-1)
            {
                push_back(str[i],counter);
            }
        } 
    	// if we have reached the end of the string, increment counter and call push_back with the symbol and counter
        else if (i == str.size()-1)
            {
                counter++;
                push_back(str[i],counter);
            }
    	// if the current character is the same as the previous one, increment the counter
        else counter++;

    }   
    }
    
}

// Constructor for copying an existing RleString object 
RleString:: RleString(const RleString& other) : head(nullptr), tail(nullptr)
{
    // Call the copyFrom method to copy the data from the existing object
    copyFrom(other);
}


// constructor for RleString class
RleString& RleString:: operator=(const RleString& other)
{
    // Check if the object being assigned is not the same object
    if (this != &other)
	{
		// Deallocate the existing memory
		free();
		// Copy elements from other object to this object
		copyFrom(other);
	}

	// Return the reference of the object being assigned to
	return *this;
}

// Destructor function for RleString class
RleString:: ~RleString()
{   
    free();
}

// toString function of RleString class
// Returns the string representation of RleString data
std::string RleString::toString() const
{
    // Initialize an empty string result
    std::string result = "";

    // Create a pointer to traverse the linked list
    Node* itterator = head;

    // Iterate over the linked list
    while (itterator)
    {
        // Append the symbol count times to the result string
        for (size_t i = 0; i < itterator->count; i++)
        {
            result += itterator->symbol;
        }

        // Move to the next node in the linked list
        itterator = itterator->next;
    }

    // Return the resulting string
    return result;
}


//This function checks if two RleString objects are equal
bool RleString::operator==(const RleString& other) const
{
    //Create two pointers to iterate through the linked lists of the two RleString objects
    Node* this_iterator = this->head;
    Node* other_iterator = other.head;

    //Check if the sizes of the two linked lists are equal
    if (this->size() != other.size())
    {
        return false;
    }
    
    //Compare each symbol and count of each node of the two linked lists
    while (this_iterator && other_iterator)
    {
        //If symbols are not equal, return false
        if (this_iterator->symbol != other_iterator->symbol)
        {
            return false;
        }
        //If counts are not equal, return false
        if (this_iterator->count != other_iterator->count)
        {
            return false;
        }

        //Move to the next node
        this_iterator= this_iterator->next;
        other_iterator= other_iterator->next;
    }
    
    //If all nodes are equal, return true
    return true;
    
}


// operator == to compare the RleString with a standard string
bool RleString::operator==(const std::string& str) const
{
    // Convert the RleString to a standard string and compare it with the input string
    return this->toString() == str; 
}

//returns the size of the RleString
size_t RleString::size() const noexcept
{
    size_t size = 0; 
    Node *itterator = head;
    
    // traverse the linked list, adding up the count of each node 
    while (itterator != nullptr)
    {
        size += itterator->count;
        itterator = itterator->next;
    }
   
    return size;
}


// Function: insertAt
// Parameters: index - the position at which to insert the character
//            value - the character to insert
// Purpose: Inserts the character 'value' at the given 'index' in the RLE string.
// Throws: std::out_of_range - if the index is greater than the size of the RLE string
// Returns: None
void RleString::insertAt(size_t index, char value)
{
    // If the index is greater than the size of the RLE string, throw an exception
    if(index > this->size())
    {
        throw std:: out_of_range("Index out of range");
    }
    
    // Convert the RLE string to a normal string
    string a = this->toString();
    
    // Insert the character 'value' at the given 'index' in the normal string
    a.insert(index,1,value);
    
    // Create a new RLE string from the modified normal string
    RleString result = a;
    
    // Free the memory of the current RLE string
    free();
    
    // Copy the values from the new RLE string to the current RLE string
    copyFrom(result);
}


void RleString:: removeAt(size_t index)
{ 
     // If the index is greater than or equal to the size of the RLE string, throw an exception
     if(index >= this->size())
    {
        throw std:: out_of_range("");
    }
    // Convert the RLE string to a normal string
    string current = this->toString();
	
    // Remove the character at the given 'index' in the normal string
    current.erase(index,1);
    
    // Create a new RLE string from the modified normal string
    RleString result = current;
    // Free the memory of the current RLE string
    free();
    //Copy the values from the new RLE string to the current RLE string
    copyFrom(result);
}

void RleString::reverse()
{
    // Initialize a pointer to the current node and set it to the head node
    Node* current = this->head;

    // Initialize pointers to the previous node and the next node
    Node* prev = nullptr;
    Node* next = nullptr;

    // Loop through the linked list and reverse the direction of the pointers
    while (current)
    {
        // Store a reference to the next node in the list
        next = current->next;

        // Reverse the direction of the current node's pointer to the next node
        current->next = prev;

        // Move the previous node pointer forward to the current node
        prev = current;

        // Move the current node pointer forward to the next node
        current = next;
    }

    // Update the head of the linked list to point to the new first node (previous to the original head)
    head = prev;
}


bool RleString::contains(const RleString& rle) const
{
    // If the RLE string being searched for is empty, return true
    if(rle.size()<1) return true;
    
    // Create two pointers to traverse the RLE strings
    Node* iterator1 = this->head;
    Node* iterator2 = rle.head;

    // While both pointers are valid
    while (iterator1 && iterator2)
    {
        // If the current symbols match
        if(iterator1->symbol==iterator2->symbol)
        {
            // Move both pointers forward
            iterator1=iterator1->next;
            iterator2 = iterator2->next;
            
            // If the end of the search string has been reached and the current symbols match, return true
            if(iterator2->next==nullptr && iterator1->symbol==iterator2->symbol)
            {
                return true;
            }
        }
        // If the current symbols do not match
        else if (iterator1->symbol != iterator2->symbol)
        {
            // Move only the first pointer forward
            iterator1 = iterator1->next;
            
            // Reset the second pointer back to the beginning of the search string
            iterator2= rle.head;
        }
    }
    

    return false;
    
}

