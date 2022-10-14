// Dois Shopper adicionam item a um notepad compartilhado

#include <thread>
#include <mutex>
#include <chrono>
#include <iostream>

unsigned int garlic_count = 0;
std::mutex chave;
using namespace std;

void shopper() {
	for (int i = 0; i < 10; i++) {
		//printf("Shopper %n is thinking ...\n", std::this_thread::get_id());
		//cout << "Shopper  is thinking ..." << std::this_thread::get_id() << endl;
		cout << "Shopper " << std::this_thread::get_id() << " is thinking ..."  <<endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		chave.lock();
		garlic_count++;
		chave.unlock();
	}
}


int main() {
	std::thread barron(shopper);
	std::thread olivia(shopper);
	barron.join();
	olivia.join();

	printf("We should buy %u  garlic.\n", garlic_count);

	//return 0;
}