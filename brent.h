#include <vector>

using std::vector;



class Brent {
public:					// Would normally be private. Decleared public for testing purposes.
	class entry {
	public:
		bool valid;
		int data;

		entry() {
			valid = false;
		}
	};

	vector<entry> data_vec;

public:

	Brent(int);
	void insert(int);
	int find_num_probes(int) const;
	double find_average_num_probes() const;

};
