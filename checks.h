#ifndef _CHECKS_H_
#define _CHECKS_H_

#include <stdint.h>

typedef enum { SubscriberCertificate, IntermediateCA, RootCA } CertType;
typedef enum { PEM, DER } CertFormat;

/* This should never happen in certificates, and violates a MUST */
#define ERR_INVALID                            0
#define ERR_ISSUER_ORG_NAME                    1
#define ERR_ISSUER_COUNTRY                     2
#define ERR_SUBJECT_ADDR                       3
#define ERR_SUBJECT_ORG_NO_PLACE               4
#define ERR_SUBJECT_NO_ORG_PLACE               5
#define ERR_INVALID_ENCODING                   6
#define ERR_STRING_WITH_NUL                    7
#define ERR_INVALID_NAME_ENTRY_TYPE            8
#define ERR_NON_PRINTABLE                      9
#define ERR_SUBJECT_COUNTRY                   10
#define ERR_DOMAIN_WITH_ORG                   11
#define ERR_IDENTITY_WITHOUT_ORG_OR_ADDRESS   12
#define ERR_NO_POLICY                         13
#define ERR_NO_SUBJECT_ALT_NAME               14
#define ERR_NOT_VERSION3                      15
#define ERR_INVALID_URL                       16
#define ERR_LONGER_60_MONTHS                  17
#define ERR_COUNTRY_SIZE                      18
#define ERR_INVALID_TIME_FORMAT               19
#define ERR_DUPLICATE_EXTENTION               20
#define ERR_INVALID_CRL_DIST_POINT            21
#define ERR_INVALID_DISPLAY_TEXT_TYPE         22
#define ERR_INVALID_DISPLAY_TEXT_LENGTH       23
#define ERR_INVALID_TYPE_USER_NOTICE          24
#define ERR_INVALID_POLICY_QUALIFIER_ID       25
#define ERR_INDIVDUAL_WITHOUT_NAME            26
#define ERR_INDIVDUAL_WITHOUT_COUNTRY         27
#define ERR_EV_WITHOUT_ORGANIZATION           28
#define ERR_EV_WITHOUT_BUSINESS               29
#define ERR_EV_WITHOUT_JURISDICTION_COUNTRY   30
#define ERR_EV_WITHOUT_NUMBER                 31
#define ERR_EV_WITHOUT_LOCALITY               32
#define ERR_EV_WITHOUT_COUNTRY                33
#define ERR_DOMAIN_WITH_STREET                34
#define ERR_DOMAIN_WITH_LOCALITY              35
#define ERR_DOMAIN_WITH_STATE                 36
#define ERR_DOMAIN_WITH_POSTAL                37

/* This violates a SHOULD (or MUST with exception that can't be checked) */
#define WARN_NON_PRINTABLE_STRING      0
#define WARN_IA5                       1
#define WARN_LONGER_39_MONTHS          2
#define WARN_CHECKED_AS_SUBSCRIBER     3
#define WARN_CHECKED_AS_CA             4
#define WARN_CRL_RELATIVE              5

/* Certificate is valid, but contains things like deprecated or not checked. */
#define INF_SUBJECT_CN                 0
#define INF_STRING_NOT_CHECKED         1        /* Software doesn't know how to check it yet. */
#define INF_CRL_NOT_URL                2
#define INF_UNKNOWN_VALIDATION         3        /* Software doesn't know OID yet. */

extern uint32_t errors[];
extern uint32_t warnings[];
extern uint32_t info[];

void check_init();
void check(unsigned char *cert_buffer, size_t cert_len, CertFormat format, CertType type);
int GetBit(uint32_t *val, int bit);
void check_finish();


#endif

