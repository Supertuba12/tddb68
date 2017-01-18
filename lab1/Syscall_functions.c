
/*Creates a new file with initial_size in bytes.
Returns true if successfully done so, otherwise false.*/
bool create(const char *file, unsigned initial_size){

}

/*Opens the given file and returns the file's fd or
"File Descriptor. This is the a unique nonnegative 
number*/
int open(const char *file){

}

/*Closes the file descriptor given as parameter.*/
void close(int fd){

}

/*Reads size bytes from an open file and returns number of
bytes actually read.*/
int read(int fd, void *buffer, unsigned size){

}

/*Tries to write size bytes from given buffer to an open file fd.
Returns number of bytes actually written.*/
int write(int fd, const void *buffer, unsigned size){

}

/*Terminate Pintos by a call to power_off(). Use with cautions and 
good knowledge as you lose information*/
void halt(void){

}
/*Terminates the current user program. Returns status to kernel*/
void exit(int status){

}