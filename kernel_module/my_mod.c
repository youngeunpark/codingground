
/**
 * @file my_mod.c
 * @date 2018/06/27
 * @author Youngeun Park
 * @brief
 * Test codes to study kernel module
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

/**
 * Static variables
 */
static int m_param_int = 1;
static char m_param_char = 'a';
static char *m_param_str;
#define BUF_LEN 100
static char m_param_strbuf[BUF_LEN];

/**
 * @return
 * NONE
 *
 * @param
 * NONE
 */
static int my_mod_main(void)
{
    printk("m_param_int = %d\n", m_param_int);
    printk("m_param_char = %c\n", m_param_char);
    printk("m_param_str = %s\n", m_param_str);
    printk("m_param_strbuf = %s\n", m_param_strbuf);
    return 0;
}

/**
 * @return
 * 0 on success, non-zero on failure
 *
 * @param
 * NONE
 */
static int my_mod_init(void)
{
    printk("my_mod_init is called\n");

    my_mod_main();

    return 0;
}

/**
 * @return
 * NONE
 *
 * @param
 * NONE
 */
static void my_mod_exit(void)
{
    printk("my_mod_exit is called\n");
}

/**
 * @brief
 * Macro declaration to expose init function of this module
 */
module_init(my_mod_init);

/**
 * @brief
 * Macro declaration to expose exit function of this module
 */
module_exit(my_mod_exit);

/**
 * @brief
 * Macro for license of this module
 */
MODULE_LICENSE("GPL");

/**
 * @brief
 * Macro for the author of this module
 */
MODULE_AUTHOR("Youngeun Park");

/**
 * @brief
 * Macro for the description of this module
 */
MODULE_DESCRIPTION("Test module to learn Kernel module API");

/**
 * @brief
 * Module parameters definitions
 *
 * @Notes
 * Perms should be 0644.
 *  Error is caused with 0777, Need to investigate...
 *
 * @Usage
 *  insmod my_mod.ko m_param_int=100 m_param_char=66 m_param_str="panzee" m_param_strbuf="hello"
 */
module_param(m_param_int, int, 0644);
MODULE_PARM_DESC(m_param_int, "Module parameter of int type, m_param_int");
module_param(m_param_char, byte, 0644);
MODULE_PARM_DESC(m_param_char, "Module parameter of byte type, m_param_char");
module_param(m_param_str, charp, 0644);
MODULE_PARM_DESC(m_param_str, "Module parameter of charp, m_param_str");
module_param_string(m_param_strbuf, m_param_strbuf, BUF_LEN, 0644);
MODULE_PARM_DESC(m_param_strbuf, "Module parameter of string, m_param_strbuf");

