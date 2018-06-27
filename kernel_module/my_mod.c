
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
 * @return
 * 0 on success, non-zero on failure
 *
 * @param
 * NONE
 */
static int my_mod_init(void)
{
    printk("my_mod_init is called\n");

    // Return 0 on success
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

