#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>

#include "../test_include/test_Caesar.hpp"


void    redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

static void encryptString(IEncryptionMethod& encryptionMethod, 
							std:: string const& toEncrypt)
{
	size_t len = toEncrypt.size();
	// encryptionMethod.reset();
	for (size_t i = 0; i < len; ++i)
	{
		encryptionMethod.encryptChar(toEncrypt[i]);
	}
	std::cout << std::endl;
}

// static void decryptString(IEncryptionMethod& encryptionMethod, std::string const& toDecrypt)
// {
// 	size_t len = toDecrypt.size();
// 	encryptionMethod.reset();
// 	for (size_t i = 0; i < len; ++i)
// 	{
// 		encryptionMethod.decryptChar(toDecrypt[i]);
// 	}
// 	std::cout << std::endl;
// }

Test(Caesar, test_Caesar)
{
	cr_assert(1 == 1);
    Caesar  c;
	encryptString(c, "Je clair Luc , ne pas ? Ze woudrai un kekos !");


}

// Test(Caesar, test_main)//, .init = redirect_all_stdout)
// {
//     Cesar c;
	// encryptString(c, "Je clair Luc , ne pas ? Ze woudrai un kekos !");
// 	decryptString(c, "Mi isirb Xhq , ew jvo ? Zf zszjyir fz ytafk !");
// 	encryptString(c, "KIKOO");
// 	encryptString(c, "LULZ XD");
// 	decryptString(c, "Ziqivun ea Ndcsg.Wji !");
// }