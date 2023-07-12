#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>

#include "../test_include/test_MyAlgorithms.hpp"

void    redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

static bool isGreaterThan(int a, int b)
{
  		return a > b;
}

static void showMe(int i)
{
		std::cout << std::setw(4) << i << ", ";
}

static void mult2(int& i)
{
  		i *= 2;
}

Test(MyAlgorithms, test_MyAlgorithms_vPrint, .init = redirect_all_stdout)
{
    	int tab[] = { 4, 9, 1, 1, 99, 8, 42, 42, 42, -1, 3 };
		int tab2[] = { 99, 1, -42, 21, 12, 21, 99, -7, 42, 42};

		std::vector<int> v1(tab, tab + sizeof(tab) / sizeof(*tab));
		std::vector<int> v2(tab2, tab2 + sizeof(tab2) / sizeof(*tab2));
		std::vector<int>::iterator it;

		std::cout << "============ Step 01 ==========" << std::endl;
		vPrint(v1, &showMe);
		vPrint(v2, &showMe);
}

Test(MyAlgorithms, test_MyAlgorithms_vHowMany, .init = redirect_all_stdout)
{
    	int tab[] = { 4, 9, 1, 1, 99, 8, 42, 42, 42, -1, 3 };
		int tab2[] = { 99, 1, -42, 21, 12, 21, 99, -7, 42, 42};

		std::vector<int> v1(tab, tab + sizeof(tab) / sizeof(*tab));
		std::vector<int> v2(tab2, tab2 + sizeof(tab2) / sizeof(*tab2));
		std::vector<int>::iterator it;

		std::cout << "============ Step 01 ==========" << std::endl;
		vPrint(v1, &showMe);
		vPrint(v2, &showMe);
		std::cout << "============ Step 02 ==========" << std::endl;
		std::cout << vHowMany(v1, 42) << std::endl;
		std::cout << vHowMany(v2, 421) << std::endl;
}

Test(MyAlgorithms, test_MyAlgorithms_vIsSimilar, .init = redirect_all_stdout)
{
    	int tab[] = { 4, 9, 1, 1, 99, 8, 42, 42, 42, -1, 3 };
		int tab2[] = { 99, 1, -42, 21, 12, 21, 99, -7, 42, 42};

		std::vector<int> v1(tab, tab + sizeof(tab) / sizeof(*tab));
		std::vector<int> v2(tab2, tab2 + sizeof(tab2) / sizeof(*tab2));
		std::vector<int>::iterator it;

		std::cout << "============ Step 01 ==========" << std::endl;
		vPrint(v1, &showMe);
		vPrint(v2, &showMe);
		std::cout << "============ Step 02 ==========" << std::endl;
		std::cout << vHowMany(v1, 42) << std::endl;
		std::cout << vHowMany(v2, 421) << std::endl;
		std::cout << "============ Step 03 ==========" << std::endl;
		std::cout << std::boolalpha << vIsSimilar(v1, tab) << std::endl;
		std::cout << std::boolalpha << vIsSimilar(v1, tab2) << std::endl;
		std::cout << std::boolalpha << vIsSimilar(v2, tab) << std::endl;
		std::cout << std::boolalpha << vIsSimilar(v2, tab2) << std::endl;
}

Test(MyAlgorithms, test_MyAlgorithms_vAssign, .init = redirect_all_stdout)
{
    	int tab[] = { 4, 9, 1, 1, 99, 8, 42, 42, 42, -1, 3 };
		int tab2[] = { 99, 1, -42, 21, 12, 21, 99, -7, 42, 42};

		std::vector<int> v1(tab, tab + sizeof(tab) / sizeof(*tab));
		std::vector<int> v2(tab2, tab2 + sizeof(tab2) / sizeof(*tab2));
		std::vector<int>::iterator it;

		std::cout << "============ Step 01 ==========" << std::endl;
		vPrint(v1, &showMe);
		vPrint(v2, &showMe);
		std::cout << "============ Step 02 ==========" << std::endl;
		std::cout << vHowMany(v1, 42) << std::endl;
		std::cout << vHowMany(v2, 421) << std::endl;
		std::cout << "============ Step 03 ==========" << std::endl;
		std::cout << std::boolalpha << vIsSimilar(v1, tab) << std::endl;
		std::cout << std::boolalpha << vIsSimilar(v1, tab2) << std::endl;
		std::cout << std::boolalpha << vIsSimilar(v2, tab) << std::endl;
		std::cout << std::boolalpha << vIsSimilar(v2, tab2) << std::endl;
		std::cout << "============ Step 04 ==========" << std::endl;
		vPrint(v1, &showMe);
		vAssign(v1.begin() + 3, v1.begin() + 5, -421);
		vPrint(v1, &showMe);
}

Test(MyAlgorithms, test_MyAlgorithms_vApply, .init = redirect_all_stdout)
{
    	int tab[] = { 4, 9, 1, 1, 99, 8, 42, 42, 42, -1, 3 };
		int tab2[] = { 99, 1, -42, 21, 12, 21, 99, -7, 42, 42};

		std::vector<int> v1(tab, tab + sizeof(tab) / sizeof(*tab));
		std::vector<int> v2(tab2, tab2 + sizeof(tab2) / sizeof(*tab2));
		std::vector<int>::iterator it;

		std::cout << "============ Step 01 ==========" << std::endl;
		vPrint(v1, &showMe);
		vPrint(v2, &showMe);
		std::cout << "============ Step 02 ==========" << std::endl;
		std::cout << vHowMany(v1, 42) << std::endl;
		std::cout << vHowMany(v2, 421) << std::endl;
		std::cout << "============ Step 03 ==========" << std::endl;
		std::cout << std::boolalpha << vIsSimilar(v1, tab) << std::endl;
		std::cout << std::boolalpha << vIsSimilar(v1, tab2) << std::endl;
		std::cout << std::boolalpha << vIsSimilar(v2, tab) << std::endl;
		std::cout << std::boolalpha << vIsSimilar(v2, tab2) << std::endl;
		std::cout << "============ Step 04 ==========" << std::endl;
		vPrint(v1, &showMe);
		vAssign(v1.begin() + 3, v1.begin() + 5, -421);
		vPrint(v1, &showMe);
		std::cout << "============ Step 05 ==========" << std::endl;
		vPrint(v1, &showMe);
		vApply(v1.begin() + 1, v1.begin() + 10, &mult2);
		vPrint(v1, &showMe);
}

Test(MyAlgorithms, test_MyAlgorithms_vGiveMeTheFirst, .init = redirect_all_stdout)
{
    	int tab[] = { 4, 9, 1, 1, 99, 8, 42, 42, 42, -1, 3 };
		int tab2[] = { 99, 1, -42, 21, 12, 21, 99, -7, 42, 42};

		std::vector<int> v1(tab, tab + sizeof(tab) / sizeof(*tab));
		std::vector<int> v2(tab2, tab2 + sizeof(tab2) / sizeof(*tab2));
		std::vector<int>::iterator it;

		std::cout << "============ Step 01 ==========" << std::endl;
		vPrint(v1, &showMe);
		vPrint(v2, &showMe);
		std::cout << "============ Step 02 ==========" << std::endl;
		std::cout << vHowMany(v1, 42) << std::endl;
		std::cout << vHowMany(v2, 421) << std::endl;
		std::cout << "============ Step 03 ==========" << std::endl;
		std::cout << std::boolalpha << vIsSimilar(v1, tab) << std::endl;
		std::cout << std::boolalpha << vIsSimilar(v1, tab2) << std::endl;
		std::cout << std::boolalpha << vIsSimilar(v2, tab) << std::endl;
		std::cout << std::boolalpha << vIsSimilar(v2, tab2) << std::endl;
		std::cout << "============ Step 04 ==========" << std::endl;
		vPrint(v1, &showMe);
		vAssign(v1.begin() + 3, v1.begin() + 5, -421);
		vPrint(v1, &showMe);
		std::cout << "============ Step 05 ==========" << std::endl;
		vPrint(v1, &showMe);
		vApply(v1.begin() + 1, v1.begin() + 10, &mult2);
		vPrint(v1, &showMe);
		std::cout << "============ Step 06 ==========" << std::endl;
		vPrint(v1, &showMe);
		it = vGiveMeTheFirst(v1, 84);
		if (it != v1.end())
				v1.erase(it, it + 3);
		vPrint(v1, &showMe);
}

Test(MyAlgorithms, test_MyAlgorithms_vFlip, .init = redirect_all_stdout)
{
    	int tab[] = { 4, 9, 1, 1, 99, 8, 42, 42, 42, -1, 3 };
		int tab2[] = { 99, 1, -42, 21, 12, 21, 99, -7, 42, 42};

		std::vector<int> v1(tab, tab + sizeof(tab) / sizeof(*tab));
		std::vector<int> v2(tab2, tab2 + sizeof(tab2) / sizeof(*tab2));
		std::vector<int>::iterator it;

		std::cout << "============ Step 01 ==========" << std::endl;
		vPrint(v1, &showMe);
		vPrint(v2, &showMe);
		std::cout << "============ Step 02 ==========" << std::endl;
		std::cout << vHowMany(v1, 42) << std::endl;
		std::cout << vHowMany(v2, 421) << std::endl;
		std::cout << "============ Step 03 ==========" << std::endl;
		std::cout << std::boolalpha << vIsSimilar(v1, tab) << std::endl;
		std::cout << std::boolalpha << vIsSimilar(v1, tab2) << std::endl;
		std::cout << std::boolalpha << vIsSimilar(v2, tab) << std::endl;
		std::cout << std::boolalpha << vIsSimilar(v2, tab2) << std::endl;
		std::cout << "============ Step 04 ==========" << std::endl;
		vPrint(v1, &showMe);
		vAssign(v1.begin() + 3, v1.begin() + 5, -421);
		vPrint(v1, &showMe);
		std::cout << "============ Step 05 ==========" << std::endl;
		vPrint(v1, &showMe);
		vApply(v1.begin() + 1, v1.begin() + 10, &mult2);
		vPrint(v1, &showMe);
		std::cout << "============ Step 06 ==========" << std::endl;
		vPrint(v1, &showMe);
		it = vGiveMeTheFirst(v1, 84);
		if (it != v1.end())
				v1.erase(it, it + 3);
		vPrint(v1, &showMe);
		std::cout << "============ Step 07 ==========" << std::endl;
		vPrint(v2, &showMe);
		vFlip(v2);
		vPrint(v2, &showMe);
}

Test(MyAlgorithms, test_MyAlgorithms_vRemoveDuplicate, .init = redirect_all_stdout)
{
    	int tab[] = { 4, 9, 1, 1, 99, 8, 42, 42, 42, -1, 3 };
		int tab2[] = { 99, 1, -42, 21, 12, 21, 99, -7, 42, 42};

		std::vector<int> v1(tab, tab + sizeof(tab) / sizeof(*tab));
		std::vector<int> v2(tab2, tab2 + sizeof(tab2) / sizeof(*tab2));
		std::vector<int>::iterator it;

		std::cout << "============ Step 01 ==========" << std::endl;
		vPrint(v1, &showMe);
		vPrint(v2, &showMe);
		std::cout << "============ Step 02 ==========" << std::endl;
		std::cout << vHowMany(v1, 42) << std::endl;
		std::cout << vHowMany(v2, 421) << std::endl;
		std::cout << "============ Step 03 ==========" << std::endl;
		std::cout << std::boolalpha << vIsSimilar(v1, tab) << std::endl;
		std::cout << std::boolalpha << vIsSimilar(v1, tab2) << std::endl;
		std::cout << std::boolalpha << vIsSimilar(v2, tab) << std::endl;
		std::cout << std::boolalpha << vIsSimilar(v2, tab2) << std::endl;
		std::cout << "============ Step 04 ==========" << std::endl;
		vPrint(v1, &showMe);
		vAssign(v1.begin() + 3, v1.begin() + 5, -421);
		vPrint(v1, &showMe);
		std::cout << "============ Step 05 ==========" << std::endl;
		vPrint(v1, &showMe);
		vApply(v1.begin() + 1, v1.begin() + 10, &mult2);
		vPrint(v1, &showMe);
		std::cout << "============ Step 06 ==========" << std::endl;
		vPrint(v1, &showMe);
		it = vGiveMeTheFirst(v1, 84);
		if (it != v1.end())
				v1.erase(it, it + 3);
		vPrint(v1, &showMe);
		std::cout << "============ Step 07 ==========" << std::endl;
		vPrint(v2, &showMe);
		vFlip(v2);
		vPrint(v2, &showMe);
		std::cout << "============ Step 08 ==========" << std::endl;
		vPrint(v2, &showMe);
		std::vector<int>::iterator newEnd = vRemoveDuplicate(v2);
		v2.resize(newEnd - v2.begin());
		vPrint(v2, &showMe);
}

Test(MyAlgorithms, test_MyAlgorithms_vToAscOrdere, .init = redirect_all_stdout)
{
    	int tab[] = { 4, 9, 1, 1, 99, 8, 42, 42, 42, -1, 3 };
		int tab2[] = { 99, 1, -42, 21, 12, 21, 99, -7, 42, 42};

		std::vector<int> v1(tab, tab + sizeof(tab) / sizeof(*tab));
		std::vector<int> v2(tab2, tab2 + sizeof(tab2) / sizeof(*tab2));
		std::vector<int>::iterator it;

		std::cout << "============ Step 01 ==========" << std::endl;
		vPrint(v1, &showMe);
		vPrint(v2, &showMe);
		std::cout << "============ Step 02 ==========" << std::endl;
		std::cout << vHowMany(v1, 42) << std::endl;
		std::cout << vHowMany(v2, 421) << std::endl;
		std::cout << "============ Step 03 ==========" << std::endl;
		std::cout << std::boolalpha << vIsSimilar(v1, tab) << std::endl;
		std::cout << std::boolalpha << vIsSimilar(v1, tab2) << std::endl;
		std::cout << std::boolalpha << vIsSimilar(v2, tab) << std::endl;
		std::cout << std::boolalpha << vIsSimilar(v2, tab2) << std::endl;
		std::cout << "============ Step 04 ==========" << std::endl;
		vPrint(v1, &showMe);
		vAssign(v1.begin() + 3, v1.begin() + 5, -421);
		vPrint(v1, &showMe);
		std::cout << "============ Step 05 ==========" << std::endl;
		vPrint(v1, &showMe);
		vApply(v1.begin() + 1, v1.begin() + 10, &mult2);
		vPrint(v1, &showMe);
		std::cout << "============ Step 06 ==========" << std::endl;
		vPrint(v1, &showMe);
		it = vGiveMeTheFirst(v1, 84);
		if (it != v1.end())
				v1.erase(it, it + 3);
		vPrint(v1, &showMe);
		std::cout << "============ Step 07 ==========" << std::endl;
		vPrint(v2, &showMe);
		vFlip(v2);
		vPrint(v2, &showMe);
		std::cout << "============ Step 08 ==========" << std::endl;
		vPrint(v2, &showMe);
		std::vector<int>::iterator newEnd = vRemoveDuplicate(v2);
		v2.resize(newEnd - v2.begin());
		vPrint(v2, &showMe);
		std::cout << "============ Step 09 ==========" << std::endl;
		vPrint(v1, &showMe);
		vToAscOrder(v1);
		vPrint(v1, &showMe);
}

Test(MyAlgorithms, test_MyAlgorithms_vToSpecificOrder, .init = redirect_all_stdout)
{
    	int tab[] = { 4, 9, 1, 1, 99, 8, 42, 42, 42, -1, 3 };
		int tab2[] = { 99, 1, -42, 21, 12, 21, 99, -7, 42, 42};

		std::vector<int> v1(tab, tab + sizeof(tab) / sizeof(*tab));
		std::vector<int> v2(tab2, tab2 + sizeof(tab2) / sizeof(*tab2));
		std::vector<int>::iterator it;

		std::cout << "============ Step 01 ==========" << std::endl;
		vPrint(v1, &showMe);
		vPrint(v2, &showMe);
		std::cout << "============ Step 02 ==========" << std::endl;
		std::cout << vHowMany(v1, 42) << std::endl;
		std::cout << vHowMany(v2, 421) << std::endl;
		std::cout << "============ Step 03 ==========" << std::endl;
		std::cout << std::boolalpha << vIsSimilar(v1, tab) << std::endl;
		std::cout << std::boolalpha << vIsSimilar(v1, tab2) << std::endl;
		std::cout << std::boolalpha << vIsSimilar(v2, tab) << std::endl;
		std::cout << std::boolalpha << vIsSimilar(v2, tab2) << std::endl;
		std::cout << "============ Step 04 ==========" << std::endl;
		vPrint(v1, &showMe);
		vAssign(v1.begin() + 3, v1.begin() + 5, -421);
		vPrint(v1, &showMe);
		std::cout << "============ Step 05 ==========" << std::endl;
		vPrint(v1, &showMe);
		vApply(v1.begin() + 1, v1.begin() + 10, &mult2);
		vPrint(v1, &showMe);
		std::cout << "============ Step 06 ==========" << std::endl;
		vPrint(v1, &showMe);
		it = vGiveMeTheFirst(v1, 84);
		if (it != v1.end())
				v1.erase(it, it + 3);
		vPrint(v1, &showMe);
		std::cout << "============ Step 07 ==========" << std::endl;
		vPrint(v2, &showMe);
		vFlip(v2);
		vPrint(v2, &showMe);
		std::cout << "============ Step 08 ==========" << std::endl;
		vPrint(v2, &showMe);
		std::vector<int>::iterator newEnd = vRemoveDuplicate(v2);
		v2.resize(newEnd - v2.begin());
		vPrint(v2, &showMe);
		std::cout << "============ Step 09 ==========" << std::endl;
		vPrint(v1, &showMe);
		vToAscOrder(v1);
		vPrint(v1, &showMe);
		std::cout << "============ Step 10 ==========" << std::endl;
		vPrint(v2, &showMe);
		vToSpecificOrder(v2, &isGreaterThan);
		vPrint(v2, &showMe);
}

Test(MyAlgorithms, test_MyAlgorithms_vShift, .init = redirect_all_stdout)
{
    	int tab[] = { 4, 9, 1, 1, 99, 8, 42, 42, 42, -1, 3 };
		int tab2[] = { 99, 1, -42, 21, 12, 21, 99, -7, 42, 42};

		std::vector<int> v1(tab, tab + sizeof(tab) / sizeof(*tab));
		std::vector<int> v2(tab2, tab2 + sizeof(tab2) / sizeof(*tab2));
		std::vector<int>::iterator it;

		std::cout << "============ Step 01 ==========" << std::endl;
		vPrint(v1, &showMe);
		vPrint(v2, &showMe);
		std::cout << "============ Step 02 ==========" << std::endl;
		std::cout << vHowMany(v1, 42) << std::endl;
		std::cout << vHowMany(v2, 421) << std::endl;
		std::cout << "============ Step 03 ==========" << std::endl;
		std::cout << std::boolalpha << vIsSimilar(v1, tab) << std::endl;
		std::cout << std::boolalpha << vIsSimilar(v1, tab2) << std::endl;
		std::cout << std::boolalpha << vIsSimilar(v2, tab) << std::endl;
		std::cout << std::boolalpha << vIsSimilar(v2, tab2) << std::endl;
		std::cout << "============ Step 04 ==========" << std::endl;
		vPrint(v1, &showMe);
		vAssign(v1.begin() + 3, v1.begin() + 5, -421);
		vPrint(v1, &showMe);
		std::cout << "============ Step 05 ==========" << std::endl;
		vPrint(v1, &showMe);
		vApply(v1.begin() + 1, v1.begin() + 10, &mult2);
		vPrint(v1, &showMe);
		std::cout << "============ Step 06 ==========" << std::endl;
		vPrint(v1, &showMe);
		it = vGiveMeTheFirst(v1, 84);
		if (it != v1.end())
				v1.erase(it, it + 3);
		vPrint(v1, &showMe);
		std::cout << "============ Step 07 ==========" << std::endl;
		vPrint(v2, &showMe);
		vFlip(v2);
		vPrint(v2, &showMe);
		std::cout << "============ Step 08 ==========" << std::endl;
		vPrint(v2, &showMe);
		std::vector<int>::iterator newEnd = vRemoveDuplicate(v2);
		v2.resize(newEnd - v2.begin());
		vPrint(v2, &showMe);
		std::cout << "============ Step 09 ==========" << std::endl;
		vPrint(v1, &showMe);
		vToAscOrder(v1);
		vPrint(v1, &showMe);
		std::cout << "============ Step 10 ==========" << std::endl;
		vPrint(v2, &showMe);
		vToSpecificOrder(v2, &isGreaterThan);
		vPrint(v2, &showMe);
		std::cout << "============ Step 11 ==========" << std::endl;
		vPrint(v2, &showMe);
		vShift(v2, 3);
		vPrint(v2, &showMe);
		vShift(v2, 7);
		vPrint(v2, &showMe);
}

Test(MyAlgorithms, test_MyAlgorithms_vFindAndModify, .init = redirect_all_stdout)
{
    	int tab[] = { 4, 9, 1, 1, 99, 8, 42, 42, 42, -1, 3 };
		int tab2[] = { 99, 1, -42, 21, 12, 21, 99, -7, 42, 42};

		std::vector<int> v1(tab, tab + sizeof(tab) / sizeof(*tab));
		std::vector<int> v2(tab2, tab2 + sizeof(tab2) / sizeof(*tab2));
		std::vector<int>::iterator it;

		std::cout << "============ Step 01 ==========" << std::endl;
		vPrint(v1, &showMe);
		vPrint(v2, &showMe);
		std::cout << "============ Step 02 ==========" << std::endl;
		std::cout << vHowMany(v1, 42) << std::endl;
		std::cout << vHowMany(v2, 421) << std::endl;
		std::cout << "============ Step 03 ==========" << std::endl;
		std::cout << std::boolalpha << vIsSimilar(v1, tab) << std::endl;
		std::cout << std::boolalpha << vIsSimilar(v1, tab2) << std::endl;
		std::cout << std::boolalpha << vIsSimilar(v2, tab) << std::endl;
		std::cout << std::boolalpha << vIsSimilar(v2, tab2) << std::endl;
		std::cout << "============ Step 04 ==========" << std::endl;
		vPrint(v1, &showMe);
		vAssign(v1.begin() + 3, v1.begin() + 5, -421);
		vPrint(v1, &showMe);
		std::cout << "============ Step 05 ==========" << std::endl;
		vPrint(v1, &showMe);
		vApply(v1.begin() + 1, v1.begin() + 10, &mult2);
		vPrint(v1, &showMe);
		std::cout << "============ Step 06 ==========" << std::endl;
		vPrint(v1, &showMe);
		it = vGiveMeTheFirst(v1, 84);
		if (it != v1.end())
				v1.erase(it, it + 3);
		vPrint(v1, &showMe);
		std::cout << "============ Step 07 ==========" << std::endl;
		vPrint(v2, &showMe);
		vFlip(v2);
		vPrint(v2, &showMe);
		std::cout << "============ Step 08 ==========" << std::endl;
		vPrint(v2, &showMe);
		std::vector<int>::iterator newEnd = vRemoveDuplicate(v2);
		v2.resize(newEnd - v2.begin());
		vPrint(v2, &showMe);
		std::cout << "============ Step 09 ==========" << std::endl;
		vPrint(v1, &showMe);
		vToAscOrder(v1);
		vPrint(v1, &showMe);
		std::cout << "============ Step 10 ==========" << std::endl;
		vPrint(v2, &showMe);
		vToSpecificOrder(v2, &isGreaterThan);
		vPrint(v2, &showMe);
		std::cout << "============ Step 11 ==========" << std::endl;
		vPrint(v2, &showMe);
		vShift(v2, 3);
		vPrint(v2, &showMe);
		vShift(v2, 7);
		vPrint(v2, &showMe);
		std::cout << "============ Step 12 ==========" << std::endl;
		vPrint(v2, &showMe);
		vFindAndModify(v2, 21, 777);
		vPrint(v2, &showMe);
}

Test(MyAlgorithms, test_MyAlgorithms_vFindAndKill, .init = redirect_all_stdout)
{
    	int tab[] = { 4, 9, 1, 1, 99, 8, 42, 42, 42, -1, 3 };
		int tab2[] = { 99, 1, -42, 21, 12, 21, 99, -7, 42, 42};

		std::vector<int> v1(tab, tab + sizeof(tab) / sizeof(*tab));
		std::vector<int> v2(tab2, tab2 + sizeof(tab2) / sizeof(*tab2));
		std::vector<int>::iterator it;

		std::cout << "============ Step 01 ==========" << std::endl;
		vPrint(v1, &showMe);
		vPrint(v2, &showMe);
		std::cout << "============ Step 02 ==========" << std::endl;
		std::cout << vHowMany(v1, 42) << std::endl;
		std::cout << vHowMany(v2, 421) << std::endl;
		std::cout << "============ Step 03 ==========" << std::endl;
		std::cout << std::boolalpha << vIsSimilar(v1, tab) << std::endl;
		std::cout << std::boolalpha << vIsSimilar(v1, tab2) << std::endl;
		std::cout << std::boolalpha << vIsSimilar(v2, tab) << std::endl;
		std::cout << std::boolalpha << vIsSimilar(v2, tab2) << std::endl;
		std::cout << "============ Step 04 ==========" << std::endl;
		vPrint(v1, &showMe);
		vAssign(v1.begin() + 3, v1.begin() + 5, -421);
		vPrint(v1, &showMe);
		std::cout << "============ Step 05 ==========" << std::endl;
		vPrint(v1, &showMe);
		vApply(v1.begin() + 1, v1.begin() + 10, &mult2);
		vPrint(v1, &showMe);
		std::cout << "============ Step 06 ==========" << std::endl;
		vPrint(v1, &showMe);
		it = vGiveMeTheFirst(v1, 84);
		if (it != v1.end())
				v1.erase(it, it + 3);
		vPrint(v1, &showMe);
		std::cout << "============ Step 07 ==========" << std::endl;
		vPrint(v2, &showMe);
		vFlip(v2);
		vPrint(v2, &showMe);
		std::cout << "============ Step 08 ==========" << std::endl;
		vPrint(v2, &showMe);
		std::vector<int>::iterator newEnd = vRemoveDuplicate(v2);
		v2.resize(newEnd - v2.begin());
		vPrint(v2, &showMe);
		std::cout << "============ Step 09 ==========" << std::endl;
		vPrint(v1, &showMe);
		vToAscOrder(v1);
		vPrint(v1, &showMe);
		std::cout << "============ Step 10 ==========" << std::endl;
		vPrint(v2, &showMe);
		vToSpecificOrder(v2, &isGreaterThan);
		vPrint(v2, &showMe);
		std::cout << "============ Step 11 ==========" << std::endl;
		vPrint(v2, &showMe);
		vShift(v2, 3);
		vPrint(v2, &showMe);
		vShift(v2, 7);
		vPrint(v2, &showMe);
		std::cout << "============ Step 12 ==========" << std::endl;
		vPrint(v2, &showMe);
		vFindAndModify(v2, 21, 777);
		vPrint(v2, &showMe);
		std::cout << "============ Step 13 ==========" << std::endl;
		vPrint(v2, &showMe);
		newEnd = vFindAndKill(v2, 777);
		v2.resize(newEnd - v2.begin());
		vPrint(v2, &showMe);
}

Test(MyAlgorithms, test_MyAlgorithms_vFusionOrderLists, .init = redirect_all_stdout)
{
    	int tab[] = { 4, 9, 1, 1, 99, 8, 42, 42, 42, -1, 3 };
		int tab2[] = { 99, 1, -42, 21, 12, 21, 99, -7, 42, 42};

		std::vector<int> v1(tab, tab + sizeof(tab) / sizeof(*tab));
		std::vector<int> v2(tab2, tab2 + sizeof(tab2) / sizeof(*tab2));
		std::vector<int>::iterator it;

		std::cout << "============ Step 01 ==========" << std::endl;
		vPrint(v1, &showMe);
		vPrint(v2, &showMe);
		std::cout << "============ Step 02 ==========" << std::endl;
		std::cout << vHowMany(v1, 42) << std::endl;
		std::cout << vHowMany(v2, 421) << std::endl;
		std::cout << "============ Step 03 ==========" << std::endl;
		std::cout << std::boolalpha << vIsSimilar(v1, tab) << std::endl;
		std::cout << std::boolalpha << vIsSimilar(v1, tab2) << std::endl;
		std::cout << std::boolalpha << vIsSimilar(v2, tab) << std::endl;
		std::cout << std::boolalpha << vIsSimilar(v2, tab2) << std::endl;
		std::cout << "============ Step 04 ==========" << std::endl;
		vPrint(v1, &showMe);
		vAssign(v1.begin() + 3, v1.begin() + 5, -421);
		vPrint(v1, &showMe);
		std::cout << "============ Step 05 ==========" << std::endl;
		vPrint(v1, &showMe);
		vApply(v1.begin() + 1, v1.begin() + 10, &mult2);
		vPrint(v1, &showMe);
		std::cout << "============ Step 06 ==========" << std::endl;
		vPrint(v1, &showMe);
		it = vGiveMeTheFirst(v1, 84);
		if (it != v1.end())
				v1.erase(it, it + 3);
		vPrint(v1, &showMe);
		std::cout << "============ Step 07 ==========" << std::endl;
		vPrint(v2, &showMe);
		vFlip(v2);
		vPrint(v2, &showMe);
		std::cout << "============ Step 08 ==========" << std::endl;
		vPrint(v2, &showMe);
		std::vector<int>::iterator newEnd = vRemoveDuplicate(v2);
		v2.resize(newEnd - v2.begin());
		vPrint(v2, &showMe);
		std::cout << "============ Step 09 ==========" << std::endl;
		vPrint(v1, &showMe);
		vToAscOrder(v1);
		vPrint(v1, &showMe);
		std::cout << "============ Step 10 ==========" << std::endl;
		vPrint(v2, &showMe);
		vToSpecificOrder(v2, &isGreaterThan);
		vPrint(v2, &showMe);
		std::cout << "============ Step 11 ==========" << std::endl;
		vPrint(v2, &showMe);
		vShift(v2, 3);
		vPrint(v2, &showMe);
		vShift(v2, 7);
		vPrint(v2, &showMe);
		std::cout << "============ Step 12 ==========" << std::endl;
		vPrint(v2, &showMe);
		vFindAndModify(v2, 21, 777);
		vPrint(v2, &showMe);
		std::cout << "============ Step 13 ==========" << std::endl;
		vPrint(v2, &showMe);
		newEnd = vFindAndKill(v2, 777);
		v2.resize(newEnd - v2.begin());
		vPrint(v2, &showMe);
		std::cout << "============ Step 14 ==========" << std::endl;
		std::vector<int> v3(v1.size() + v2.size());

		vToAscOrder(v1);
		vToAscOrder(v2);
		vPrint(v1, &showMe);
		vPrint(v2, &showMe);
		vPrint(v3, &showMe);
		vFusionOrderedLists(v1, v2, v3);
		vPrint(v3, &showMe);
}