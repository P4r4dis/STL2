#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>

#include "../test_include/test_Caesar.hpp"
#include "../test_include/test_OneTime.hpp"


void    redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

static void encryptString(IEncryptionMethod& encryptionMethod, 
							std:: string const& toEncrypt)
{
	size_t len = toEncrypt.size();
	encryptionMethod.reset();
	for (size_t i = 0; i < len; ++i)
	{
		encryptionMethod.encryptChar(toEncrypt[i]);
	}
	std::cout << std::endl;
}

static void decryptString(IEncryptionMethod& encryptionMethod, std::string const& toDecrypt)
{
	size_t len = toDecrypt.size();
	encryptionMethod.reset();
	for (size_t i = 0; i < len; ++i)
	{
		encryptionMethod.decryptChar(toDecrypt[i]);
	}
	std::cout << std::endl;
}

Test(Caesar, test_Caesar_encryptChar, .init = redirect_all_stdout)
{
	cr_assert(1 == 1);
    Caesar  c;
	encryptString(c, "Je clair Luc, ne pas ? Ze woudrai un kekos !");
    cr_assert_stdout_eq_str("Mi isirb Xhq, ew jvo ? Zf zszjyir fz ytafk !\n");
}

Test(Caesar, test_Caesar_decryptChar, .init = redirect_all_stdout)
{
	cr_assert(1 == 1);
    Caesar  c;
	decryptString(c, "Mi isirb Xhq, ew jvo ? Zf zszjyir fz ytafk !");
    cr_assert_stdout_eq_str("Je clair Luc, ne pas ? Ze woudrai un kekos !\n");

}

Test(Caesar, test_main, .init = redirect_all_stdout)
{
    Caesar c;
	encryptString(c, "Je clair Luc, ne pas ? Ze woudrai un kekos !");
	decryptString(c, "Mi isirb Xhq, ew jvo ? Zf zszjyir fz ytafk !");
	encryptString(c, "KIKOO");
	encryptString(c, "LULZ XD");
	decryptString(c, "Ziqivun ea Ndcsg.Wji !");
    cr_assert_stdout_eq_str("Mi isirb Xhq, ew jvo ? Zf zszjyir fz ytafk !\n\
Je clair Luc, ne pas ? Ze woudrai un kekos !\n\
NMPUV\nOYQF FM\nWelcome to Zombo.Com !\n");

}

Test(OneTime, test_OneTime_encrypt, .init = redirect_all_stdout)
{
    OneTime  oneTime("bD");

	encryptString(oneTime, "A bah zour !");
    cr_assert_stdout_eq_str("B cdi arvu !\n");
}

Test(OneTime, test_OneTime_decrypt, .init = redirect_all_stdout)
{
    OneTime  oneTime("bD");

	decryptString(oneTime, "B cdi arvu !");
    cr_assert_stdout_eq_str("A bah zour !\n");
}

Test(OneTime, test_OneTime_main, .init = redirect_all_stdout)
{
	Caesar c;
	OneTime o("DedeATraversLesBrumes");
	OneTime t("TheCakeIsALie");

	encryptString(c, "Je clair Luc, ne pas ? Ze woudrai un kekos !");
	decryptString(c, "Mi isirb Xhq, ew jvo ? Zf zszjyir fz ytafk !");
	encryptString(c, "KIKOO");
	encryptString(c, "LULZ XD");
	decryptString(c, "Ziqivun ea Ndcsg.Wji !");
	encryptString(t, "Prend garde Lion, ne te trompes pas de voie !");
	encryptString(o, "De la musique et du bruit !");
	encryptString(t, "Kion li faras? Li studas kaj programas!");
	decryptString(t, "Iyipd kijdp Pbvr, xi le bvhttgs tik om ovmg !");
	decryptString(o, "Gi pa dunmhmp wu xg tuylx !");
	decryptString(t, "Dpsp vm xaciw? Pk cxcvad otq rrykzsmla!");

    cr_assert_stdout_eq_str("Mi isirb Xhq, ew jvo ? Zf zszjyir fz ytafk !\n"
"Je clair Luc, ne pas ? Ze woudrai un kekos !\n"
"NMPUV\n"
"OYQF FM\n"
"Welcome to Zombo.Com !\n"
"Iyipd kijdp Pbvr, xi le bvhttgs tik om ovmg !\n"
"Gi pa dunmhmp wu xg tuylx !\n"
"Dpsp vm xaciw? Pk cxcvad otq rrykzsmla!\n"
"Prend garde Lion, ne te trompes pas de voie !\n"
"De la musique et du bruit !\n"
"Kion li faras? Li studas kaj programas!\n");
}