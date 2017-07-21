#ifndef __RADIX_H__
#define __RADIX_H__
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>


#define RADIX_BITTEST(x, y) ((x) & (y))

#define RADIX_NODE_USERDATA(node, type) \
    ((type *)(((node) != NULL) ? (((node)->prefix != NULL) ? \
                (node)->prefix->user_data_result : NULL) : NULL))

typedef struct RadixUserData_ {
    /* holds the netmask value that corresponds to this user data pointer */
    uint8_t netmask;
    /* holds a pointer to the user data associated with the particular netmask */
    void *user;
    /* pointer to the next user data in the list */
    struct RadixUserData_ *next;
} RadixUserData;

typedef struct RadixPrefix_ {
    /* length of the stream */
    uint16_t bitlen;

    /* the key that has been stored in the tree */
    uint8_t *stream;

    /* any user data that has to be associated with this key.  We need a user
     * data field for each netblock value possible since one ip can be associated
     * with any of the the 32 or 128 netblocks.  Also for non-ips, we store the
     * netmask as 255 in SCRadixUserData->netmask */
    RadixUserData *user_data;

    /* Used to hold the user data from radix tree search.  More of a convenience
     * that lets anyone using the API, directly get a reference to the user
     * data which is associated with the search results */
    void *user_data_result;
} RadixPrefix;

typedef struct RadixNode_ {
    /* the bit position where the bits differ in the nodes children.  Used
     * to determine the path to be taken during a lookup*/
    uint16_t bit;

    /* holds a list of netmaks that come under this node in the tree */
    uint8_t *netmasks;
    /* total no of netmasks that are registered under this node */
    int netmask_cnt;

    /* holds the prefix that the path to this node holds */
    RadixPrefix *prefix;

    /* the left and the right children of a node */
    struct RadixNode_ *left, *right;

    /* the parent node for this tree */
    struct RadixNode_ *parent;
} RadixNode;

typedef struct RadixTree_ {
    /* the root node in the radix tree */
    RadixNode *head;

    /* function pointer that is supplied by the user to free the user data
     * held by the user field of SCRadixNode */
    void (*PrintData)(void *);
    void (*Free)(void *);
} RadixTree;


struct in_addr *RadixValidateIPV4Address(const char *);
struct in6_addr CRadixValidateIPV6Address(const char *);
void RadixChopIPAddressAgainstNetmask(uint8_t *, uint8_t, uint16_t);

RadixTree *RadixCreateRadixTree(void (*Free)(void*), void (*PrintData)(void*));
void RadixReleaseRadixTree(RadixTree *);

RadixNode *RadixAddKeyGeneric(uint8_t *, uint16_t, RadixTree *, void *);
RadixNode *RadixAddKeyIPV4(uint8_t *, RadixTree *, void *);
RadixNode *RadixAddKeyIPV6(uint8_t *, RadixTree *, void *);
RadixNode *RadixAddKeyIPV4Netblock(uint8_t *, RadixTree *, void *, uint8_t);
RadixNode *RadixAddKeyIPV6Netblock(uint8_t *, RadixTree *, void *, uint8_t);
RadixNode *RadixAddKeyIPV4String(const char *, RadixTree *, void *);
RadixNode *RadixAddKeyIPV6String(const char *, RadixTree *, void *);

void RadixRemoveKeyGeneric(uint8_t *, uint16_t, RadixTree *);
void RadixRemoveKeyIPV4Netblock(uint8_t *, RadixTree *, uint8_t);
void RadixRemoveKeyIPV4(uint8_t *, RadixTree *);
void RadixRemoveKeyIPV6Netblock(uint8_t *, RadixTree *, uint8_t);
void RadixRemoveKeyIPV6(uint8_t *, RadixTree *);

RadixNode *RadixFindKeyGeneric(uint8_t *, uint16_t, RadixTree *);

RadixNode *RadixFindKeyIPV4ExactMatch(uint8_t *, RadixTree *);
RadixNode *RadixFindKeyIPV4Netblock(uint8_t *, RadixTree *, uint8_t);
RadixNode *RadixFindKeyIPV4BestMatch(uint8_t *, RadixTree *);

RadixNode *RadixFindKeyIPV6ExactMatch(uint8_t *, RadixTree *);
RadixNode *RadixFindKeyIPV6Netblock(uint8_t *, RadixTree *, uint8_t);
RadixNode *RadixFindKeyIPV6BestMatch(uint8_t *, RadixTree *);

void RadixPrintTree(RadixTree *);
void RadixPrintNodeInfo(RadixNode *, int,  void (*PrintData)(void*));


#endif /* __RADIX_H__ */
