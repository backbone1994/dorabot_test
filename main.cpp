#include <iostream>
#include <fstream>
#include <string>
#include <tuple>
#include <list>
#include <cstdint>
#include <inttypes.h>
#include <exception>
#include <functional>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
/* Don't forget to add your necessary header files here
*/
#include "meta.hh"

#error "Please write your full name here thanks, I'm MuLei, glad to know you"
#define YangLiXiao

/* From now on, don't look any code here unless you're told so, don't be lost.
* Save your time, you don't have much time.
* I expect you have good editor for coding, and you should be good at it, since
* you have to follow the WHITE-RABBITs in order.
* Pay attention, I'll give you hints if any necessary.
* Good luck!
* Now, find WHITE-RABBIT(1), go!
*/

class MyTask : public DrTask
{
public:
	MyTask(std::string your_name) : DrTask(your_name) {};
	~MyTask() { /* feel free to add your destroy code */ };
	void greeting(void) override;
	void run(void) override;
	void load(std::string filename) override;
	void do_the_maths(void) override;
	void finish_the_work(void) override;
	std::string jabberwocky(std::string s);
	static bool is_prime(uint64_t n);
	static std::list<uint64_t> get_all_prime_divisors(uint64_t n);
protected:
	/* WHITE-RABBIT(5):
	* Define a protected attribute to hold the data which should be processed later.
	*        The attribute name must be `data_', but the type of `data_' depends on your
	*        design.
	* HINT: The test data could be very large, so you may consider the efficiency.
	* When you finish, go for WHITE-RABBIT(6)
	*/
#error "uncomment the lines below to define data_ with your preferred type"
	// Feel free to set the size of data if you need it
	// size_t size_;
	std::string data_;
};

std::string MyTask::jabberwocky(std::string s)
{
	/* WHITE-RABBIT(2)
	* Let's warm up, MyTask class ought to be initialized with your name and stored
	* to name_, now let's do some magic to encode your name:
	* In a given string, change the position of each neighbour characters, each time
	* the character has been moved, it won't be moved again. If there's no neighbour
	* then just keep it.
	* For example: MuLei -> uMeLi
	*/
	for (int i = 0; i < s.size; i++) {
		if (i + 1 < s.size) {
			std::swap(s[i], s[i + 1]);
			i++;
		}
	}
	// TODO

	/* When you finish, return your result and go for WHITE-RABBIT(3) */
	return s;
}

void MyTask::greeting(void)
{
	std::cout << "Dorabot programming test version " << version_ << std::endl;
	std::cout << "The candidate name is " << name_ << std::endl;

	if (!jabberwocky(jabberwocky(name_)).compare(name_))
		printf("Good! You killed Jabberwocky!\n");
	else
		printf("Jabberwocky killed you! Try it again!\n");
}

void MyTask::finish_the_work(void)
{
	/* WHITE-RABBIT(13)
	* Now you have 3 attributes computed by you before: sn_, pk_, sk_
	*
	* Step-1
	* Read each character C in data_ one by one, and encrypt them, then write to
	* a new file. The output filename should be "letter".
	* The encryption method is:
	* C multiply itself sk_ times, then mod sn_
	*
	* Step-2
	* Write pk_ to a file named "key.pub" in string, the format is: pk_[newline]sn_
	* Write sk_ to a file named "key.prv" in string, the format is: sk_[newline]sn_
	* NOTE: [newline] means a newline, don't output a string "[newline]" or you'll
	*       be mocked just like someone before.
	*/

	// TODO
	std::ofstream letter("letter", std::ios::out | std::ios::app);
	std::ofstream pub("key.pub", std::ios::out | std::ios::app);
	std::ofstream prv("key.prv", std::ios::out | std::ios::app);
	for (auto&C : data_) {
		for (int i = 0; i < sk_; i++) {
			C *= C;
		}
		C %= sn_;
	}
	letter << data_ ;
	pub << pk_ << std::endl<<sn_;
	prv << sk_ << std::endl << sn_;
#error "Don't miss finish_the_work()"
	// Go for WHITE-RABBIT(14)
}

void MyTask::run(void)
{
	/* WHITE-RABBIT(1)
	* Finish this function to run the task.
	*/

	/* The first task is not hard.
	* Take it easy, you should be good enough to get the 1st point here.
	* Now jump to WHITE-RABBIT(2)
	*/
	greeting();

	/* WHITE-RABBIT(3)
	* Now you should finish load() function
	* Go for WHITE-RABBIT(4)
	*/
	load(TEST_DATA);

	/* WHITE-RABBIT(7)
	* Now you should finish do_the_math() function
	* Go for WHITE-RABBIT(8)
	*/
	do_the_maths();

	/* WHITE-RABBIT(12)
	* I need you do me a favor, I have a letter for someone, but it's too dangerous
	* to deliver it by myself. I trust you, and you happened to finish some maths work
	* to help to encrypt it. Now I want you to encrypt it, the data was loaded to data_
	* by you, remember it?
	* Now go for WHITE-RABBIT(13), it's the final coding work, good luck!
	*/
	finish_the_work();

	/* WHITE-RABBIT(14)
	* Good, if you think you finished all the tasks so far, just save and quit,
	* then run `make run' and follow the instructions. You must debug your code
	* before next step if there's any error.
	*/

	end();
}

void MyTask::load(std::string filename)
{
	/* WHITE-RABBIT(4)
	* Finish this function to load data, and store it to data_
	* HINT: When I review your program, I'll load huge data set for testing.
	*       So try your best to make it efficient as possible.
	*       You'll get extra point as reward for good performance.
	*/
	std::ifstream file(filename, std::ios::in | std::ios::binary);
	if (file)
	{
		file.seekg(0, std::ios::end);
		data_.resize(file.tellg());
		file.seekg(0, std::ios::beg);
		file.read(&data_[0], data_.size());
		file.close();
	}
	/* Go for WHITE-RABBIT(5) to finish the data type define. */

	/* WHITE-RABBIT(6) here */

	// TODO

#error "Please finish load(filename)"
	/* When you finish, go for WHITE-RABBIT(7) */
}

bool MyTask::is_prime(uint64_t n)
{
	bool result = false;
	int t = 1;
	if (n<2)
	{
		return result;
	}
	for (int i = 2; i < sqrt(n) + 1; i++)
	{
		if (n%i == 0)
		{
			t = 0;
			break;
		}
	}
	if (t) result = true;
	// WHITE-RABBIT(10)

#error "Please implement is_prime(n)"
	// Go for WHITE-RABBIT(11) to finish the rest task
	return result;
}

std::list<uint64_t> MyTask::get_all_prime_divisors(uint64_t n)
{
	/* WHITE-RABBIT(9)
	* For example:
	* get_all_prime_divisors(45) returns {5, 3} as a list.
	* HINT-1: The order matters, make sure it's sorted from max to min.
	* HINT-2: Don't include 1.
	*/
	std::list<uint64_t> list;
	for (int i = 2; i <= n; i++) {
		bool m = true;
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				m = false;
				break;
			}
		}
		if (m) {
			list.push_front(i);
		}
	}
	/* Go for WHITE-RABBIT(10) to implement is_prime(n) then come back.
	* WHITE-RABBIT(11)
	* Finish the rest task
	*/

	// TODO
#error "Please finish get_all_prime_divisors(n) function"

	// When you finish, go for WHITE-RABBIT(12)
	return list;
}

void MyTask::do_the_maths(void)
{
	/* WHITE-RABBIT(8)
	* Now I give you two integers, n1 and n2
	* I promise they're NOT prime number.
	*/
	uint64_t n1, n2;
	_M(n1, n2) = get_my_numbers();

	/* Do you know prime divisors?
	* That is to say, 5 is divisor of 45, since 45/5 is an integer 9,
	* and 5 is a prime number, which can only be divided by 1 and itself.
	* So 5 is prime divisor of 45.
	* Please find out all prime divisors of given integer, and return as a list.
	* HINT: We've used a lot of uint64_t integer. Any time you want to print them
	*       out for debugging, you have to use PRId64 by C/C++ standard, for example:
	*       printf("%" PRId64 "\n", t);
	* Now go for WHITE-RABBIT(9) to finish get_all_prime_divisors(n)
	*/
	let_me_check_it(get_all_prime_divisors);

	uint64_t p1 = min(get_all_prime_divisors(n1));
	uint64_t p2 = min(get_all_prime_divisors(n2));
	sn_ = p1*p2;
	phi_ = (p1 - 1)*(p2 - 1);
	sk_ = get_exponent();
	pk_ = multiplicative_inverse();
}

int main(void)
{
	MyTask t(MY_NAME);
	t.run();

	return 0;
}