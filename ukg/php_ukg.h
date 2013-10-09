/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2007 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id: header,v 1.16.2.1.2.1 2007/01/01 19:32:09 iliaa Exp $ */

#ifndef PHP_UKG_H
#define PHP_UKG_H

extern zend_module_entry ukg_module_entry;
#define phpext_ukg_ptr &ukg_module_entry

#ifdef PHP_WIN32
#define PHP_UKG_API __declspec(dllexport)
#else
#define PHP_UKG_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(ukg);
PHP_MSHUTDOWN_FUNCTION(ukg);
PHP_RINIT_FUNCTION(ukg);
PHP_RSHUTDOWN_FUNCTION(ukg);
PHP_MINFO_FUNCTION(ukg);

PHP_FUNCTION(ukg_getkey);
PHP_FUNCTION(ukg_key2info);

/* 
  	Declare any global variables you may need between the BEGIN
	and END macros here:     

ZEND_BEGIN_MODULE_GLOBALS(ukg)
	long  global_value;
	char *global_string;
ZEND_END_MODULE_GLOBALS(ukg)
*/

/* In every utility function you add that needs to use variables 
   in php_ukg_globals, call TSRMLS_FETCH(); after declaring other 
   variables used by that function, or better yet, pass in TSRMLS_CC
   after the last function argument and declare your utility function
   with TSRMLS_DC after the last declared argument.  Always refer to
   the globals in your function as UKG_G(variable).  You are 
   encouraged to rename these macros something shorter, see
   examples in any other php module directory.
*/

#ifdef ZTS
#define UKG_G(v) TSRMG(ukg_globals_id, zend_ukg_globals *, v)
#else
#define UKG_G(v) (ukg_globals.v)
#endif

#endif	/* PHP_UKG_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
