#include <string.h>

#include "valip.h"

int alldig (const char *string)
{
    const char *cp;

    if (*string == 0)
        return (0);
    for (cp = string; *cp != 0; cp++)
        if (!ISDIGIT(*cp))
            return (0);
    return (1);
}


/* valid_hostname - screen out bad hostnames */
int valid_hostname (const char *name)
{
    const char *cp;
    int     label_length = 0;
    int     label_count = 0;
    int     non_numeric = 0;
    int     ch;

    /*
     * Trivial cases first.
     */
    if (*name == 0) {
        return (0);
    }

    /*
     * Find bad characters or label lengths. Find adjacent delimiters.
     */
    for (cp = name; (ch = *(unsigned char *) cp) != 0; cp++) {
        if (ISALNUM(ch) || ch == '_') {                /* grr.. */
            if (label_length == 0)
                label_count++;
            label_length++;
            if (label_length > VALID_LABEL_LEN) {
                return (0);
            }
            if (!ISDIGIT(ch))
                non_numeric = 1;
        } else if (ch == '.') {
            if (label_length == 0 || cp[1] == 0) {
                return (0);
            }
            label_length = 0;
        } else if (ch == '-') {
            non_numeric = 1;
            label_length++;
            if (label_length == 1 || cp[1] == 0 || cp[1] == '.') {
                return (0);
            }
        }
#ifdef SLOPPY_VALID_HOSTNAME
        else if (ch == ':' && valid_ipv6_hostaddr(name, DONT_GRIPE)) {
            non_numeric = 0;
            break;
        }
#endif
        else {
            return (0);
        }
    }

    if (non_numeric == 0) {
#ifndef SLOPPY_VALID_HOSTNAME
        return (0);
#endif
    }
    if (cp - name > VALID_HOSTNAME_LEN) {
        return (0);
    }
    return (1);
}


/* valid_hostaddr - verify numerical address syntax */
int valid_hostaddr (const char *addr)
{
    /*
     * Trivial cases first.
     */
    if (*addr == 0) {
        return (0);
    }

    /*
     * Protocol-dependent processing next.
     */
    if (strchr(addr, ':') != 0)
        return (valid_ipv6_hostaddr(addr));
    else
        return (valid_ipv4_hostaddr(addr));
}

/* valid_ipv4_hostaddr - test dotted quad string for correctness */
int valid_ipv4_hostaddr (const char *addr)
{
    const char *cp;
    int     in_byte = 0;
    int     byte_count = 0;
    int     byte_val = 0;
    int     ch;

#define BYTES_NEEDED        4

    /*
     * Scary code to avoid sscanf() overflow nasties.
     *
     * This routine is called by valid_ipv6_hostaddr(). It must not call that
     * routine, to avoid deadly recursion.
     */
    for (cp = addr; (ch = *(unsigned const char *) cp) != 0; cp++) {
        if (ISDIGIT(ch)) {
            if (in_byte == 0) {
                in_byte = 1;
                byte_val = 0;
                byte_count++;
            }
            byte_val *= 10;
            byte_val += ch - '0';
            if (byte_val > 255) {
                return (0);
            }
        } else if (ch == '.') {
            if (in_byte == 0 || cp[1] == 0) {
                return (0);
            }
            /* XXX Allow 0.0.0.0 but not 0.1.2.3 */
            if (byte_count == 1 && byte_val == 0 && addr[strspn(addr, "0.")]) {
                return (0);
            }
            in_byte = 0;
        } else {
            return (0);
        }
    }

    if (byte_count != BYTES_NEEDED) return (0);
    return (1);
}

/* valid_ipv6_hostaddr - validate IPv6 address syntax */
int  valid_ipv6_hostaddr (const char *addr)
{
    int     null_field = 0;
    int     field = 0;
    unsigned char *cp = (unsigned char *) addr;
    int     len = 0;

    /*
     * FIX 200501 The IPv6 patch validated syntax with getaddrinfo(), but I
     * am not confident that everyone's system library routines are robust
     * enough, like buffer overflow free. Remember, the valid_hostmumble()
     * routines are meant to protect Postfix against malformed information in
     * data received from the network.
     *
     * We require eight-field hex addresses of the form 0:1:2:3:4:5:6:7,
     * 0:1:2:3:4:5:6a.6b.7c.7d, or some :: compressed version of the same.
     *
     * Note: the character position is advanced inside the loop. I have added
     * comments to show why we can't get stuck.
     */
    for (;;) {
        switch (*cp) {
        case 0:
            /* Terminate the loop. */
            if (field < 2) {
                return (0);
            } else if (len == 0 && null_field != field - 1) {
                return (0);
            } else
                return (1);
        case '.':
            /* Terminate the loop. */
            if (field < 2 || field > 6) {
                return (0);
            } else
                /* NOT: valid_hostaddr(). Avoid recursion. */
                return (valid_ipv4_hostaddr((char *) cp - len));
        case ':':
            /* Advance by exactly 1 character position or terminate. */
            if (field == 0 && len == 0 && ISALNUM(cp[1])) {
                return (0);
            }
            field++;
            if (field > 7) {
                return (0);
            }
            cp++;
            len = 0;
            if (*cp == ':') {
                if (null_field > 0) {
                    return (0);
                }
                null_field = field;
            }
            break;
        default:
            /* Advance by at least 1 character position or terminate. */
            len = strspn((char *) cp, "0123456789abcdefABCDEF");
            if (len /* - strspn((char *) cp, "0") */ > 4) {
                return (0);
            }
            if (len <= 0) {
                return (0);
            }
            cp += len;
            break;
        }
    }
}

/* valid_hostport - validate numeric port */
int valid_hostport (const char *str)
{
    int  port;

    if (str[0] == '0' && str[1] != 0) {
        return (0);
    }
    if (alldig(str) == 0) {
        return (0);
    }
    if (strlen(str) > strlen("65535") || (port = atoi(str)) > 65535 || port < 0) {
        return (0);
    }
    return (1);
}


