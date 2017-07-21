#include "xradix.h"
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

int RadixTestInsertion01(void)
{
    RadixTree *tree = NULL;
    RadixNode *node[2];

    int result = 1;

    tree = RadixCreateRadixTree(free, NULL);


    node[0] = RadixAddKeyGeneric((uint8_t *)"abaa", 32, tree, NULL);
    node[1] = RadixAddKeyGeneric((uint8_t *)"abab", 32, tree, NULL);

    result &= (tree->head->bit == 30);
    result &= (tree->head->right == node[0]);
    result &= (tree->head->left == node[1]);

    RadixReleaseRadixTree(tree);

    return result;
}

int RadixTestInsertion02(void)
{
    RadixTree *tree = NULL;
    int result = 1;

    tree = RadixCreateRadixTree(free, NULL);

    RadixAddKeyGeneric((uint8_t *)"aaaaaa", 48, tree, NULL);
    RadixAddKeyGeneric((uint8_t *)"aaaaab", 48, tree, NULL);
    RadixAddKeyGeneric((uint8_t *)"aaaaaba", 56, tree, NULL);
    RadixAddKeyGeneric((uint8_t *)"abab", 32, tree, NULL);
    RadixReleaseRadixTree(tree);

    /* If we don't have a segfault till here we have succeeded :) */
    return result;
}

int RadixTestIPV4Insertion03(void)
{
    RadixTree *tree = NULL;
    struct sockaddr_in servaddr;
    int result = 1;

    tree = RadixCreateRadixTree(free, NULL);

    /* add the keys */
    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.168.1.1", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4((uint8_t *)&servaddr.sin_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.168.1.2", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4((uint8_t *)&servaddr.sin_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.167.1.3", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4((uint8_t *)&servaddr.sin_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.167.1.4", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4((uint8_t *)&servaddr.sin_addr, tree, NULL);

    /* add a key that already exists in the tree */
    RadixAddKeyIPV4((uint8_t *)&servaddr.sin_addr, tree, NULL);

    /* test for the existance of a key */
    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.168.1.6", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4ExactMatch((uint8_t *)&servaddr.sin_addr, tree) == NULL);

    /* test for the existance of a key */
    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.167.1.4", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4ExactMatch((uint8_t *)&servaddr.sin_addr, tree) != NULL);

    /* continue adding keys */
    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "220.168.1.2", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4((uint8_t *)&servaddr.sin_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.168.1.5", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4((uint8_t *)&servaddr.sin_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.168.1.18", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4((uint8_t *)&servaddr.sin_addr, tree, NULL);

    /* test the existence of keys */
    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.168.1.3", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4ExactMatch((uint8_t *)&servaddr.sin_addr, tree) == NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "127.234.2.62", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4ExactMatch((uint8_t *)&servaddr.sin_addr, tree) == NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.168.1.1", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4ExactMatch((uint8_t *)&servaddr.sin_addr, tree) != NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.168.1.5", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4ExactMatch((uint8_t *)&servaddr.sin_addr, tree) != NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.168.1.2", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4ExactMatch((uint8_t *)&servaddr.sin_addr, tree) != NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.167.1.3", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4ExactMatch((uint8_t *)&servaddr.sin_addr, tree) != NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.167.1.4", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4ExactMatch((uint8_t *)&servaddr.sin_addr, tree) != NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "220.168.1.2", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4ExactMatch((uint8_t *)&servaddr.sin_addr, tree) != NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.168.1.18", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4ExactMatch((uint8_t *)&servaddr.sin_addr, tree) != NULL);

    RadixReleaseRadixTree(tree);

    return result;
}

int RadixTestIPV4Removal04(void)
{
    RadixTree *tree = NULL;
    struct sockaddr_in servaddr;
    int result = 1;

    tree = RadixCreateRadixTree(free, NULL);

    /* add the keys */
    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.168.1.1", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4((uint8_t *)&servaddr.sin_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.168.1.2", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4((uint8_t *)&servaddr.sin_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.167.1.3", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4((uint8_t *)&servaddr.sin_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.167.1.4", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4((uint8_t *)&servaddr.sin_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "220.168.1.2", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4((uint8_t *)&servaddr.sin_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.168.1.5", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4((uint8_t *)&servaddr.sin_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.168.1.18", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4((uint8_t *)&servaddr.sin_addr, tree, NULL);

    /* remove the keys from the tree */
    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.168.1.1", &servaddr.sin_addr) <= 0)
        return 0;
    RadixRemoveKeyIPV4((uint8_t *)&servaddr.sin_addr, tree);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.167.1.3", &servaddr.sin_addr) <= 0)
        return 0;
    RadixRemoveKeyIPV4((uint8_t *)&servaddr.sin_addr, tree);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.167.1.4", &servaddr.sin_addr) <= 0)
        return 0;
    RadixRemoveKeyIPV4((uint8_t *)&servaddr.sin_addr, tree);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.168.1.18", &servaddr.sin_addr) <= 0)
        return 0;
    RadixRemoveKeyIPV4((uint8_t *)&servaddr.sin_addr, tree);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.167.1.1", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4ExactMatch((uint8_t *)&servaddr.sin_addr, tree) == NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.168.1.2", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4ExactMatch((uint8_t *)&servaddr.sin_addr, tree) != NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.167.1.3", &servaddr.sin_addr) <= 0)
        return 0;
    RadixRemoveKeyIPV4((uint8_t *)&servaddr.sin_addr, tree);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "220.168.1.2", &servaddr.sin_addr) <= 0)
        return 0;
    RadixRemoveKeyIPV4((uint8_t *)&servaddr.sin_addr, tree);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.168.1.5", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4ExactMatch((uint8_t *)&servaddr.sin_addr, tree) != NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.168.1.2", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4ExactMatch((uint8_t *)&servaddr.sin_addr, tree) != NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.168.1.2", &servaddr.sin_addr) <= 0)
        return 0;
    RadixRemoveKeyIPV4((uint8_t *)&servaddr.sin_addr, tree);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.168.1.5", &servaddr.sin_addr) <= 0)
        return 0;
    RadixRemoveKeyIPV4((uint8_t *)&servaddr.sin_addr, tree);

    result &= (tree->head == NULL);

    RadixReleaseRadixTree(tree);

    return result;
}

int RadixTestCharacterInsertion05(void)
{
    RadixTree *tree = NULL;
    int result = 1;

    tree = RadixCreateRadixTree(free, NULL);

    /* Let us have our team here ;-) */
    RadixAddKeyGeneric((uint8_t *)"Victor", 48, tree, NULL);
    RadixAddKeyGeneric((uint8_t *)"Matt", 32, tree, NULL);
    RadixAddKeyGeneric((uint8_t *)"Josh", 32, tree, NULL);
    RadixAddKeyGeneric((uint8_t *)"Margaret", 64, tree, NULL);
    RadixAddKeyGeneric((uint8_t *)"Pablo", 40, tree, NULL);
    RadixAddKeyGeneric((uint8_t *)"Brian", 40, tree, NULL);
    RadixAddKeyGeneric((uint8_t *)"Jasonish", 64, tree, NULL);
    RadixAddKeyGeneric((uint8_t *)"Jasonmc", 56, tree, NULL);
    RadixAddKeyGeneric((uint8_t *)"Nathan", 48, tree, NULL);
    RadixAddKeyGeneric((uint8_t *)"Anoop", 40, tree, NULL);

    result &= (RadixFindKeyGeneric((uint8_t *)"Victor", 48, tree) != NULL);
    result &= (RadixFindKeyGeneric((uint8_t *)"Matt", 32, tree) != NULL);
    result &= (RadixFindKeyGeneric((uint8_t *)"Josh", 32, tree) != NULL);
    result &= (RadixFindKeyGeneric((uint8_t *)"Margaret", 64, tree) != NULL);
    result &= (RadixFindKeyGeneric((uint8_t *)"Pablo", 40, tree) != NULL);
    result &= (RadixFindKeyGeneric((uint8_t *)"Brian", 40, tree) != NULL);
    result &= (RadixFindKeyGeneric((uint8_t *)"Jasonish", 64, tree) != NULL);
    result &= (RadixFindKeyGeneric((uint8_t *)"Jasonmc", 56, tree) != NULL);
    result &= (RadixFindKeyGeneric((uint8_t *)"Nathan", 48, tree) != NULL);
    result &= (RadixFindKeyGeneric((uint8_t *)"Anoop", 40, tree) != NULL);

    result &= (RadixFindKeyGeneric((uint8_t *)"bamboo", 48, tree) != NULL);
    result &= (RadixFindKeyGeneric((uint8_t *)"bool", 32, tree) == NULL);
    result &= (RadixFindKeyGeneric((uint8_t *)"meerkat", 56, tree) == NULL);
    result &= (RadixFindKeyGeneric((uint8_t *)"Victor", 48, tree) == NULL);

    RadixReleaseRadixTree(tree);

    return result;
}

int RadixTestCharacterRemoval06(void)
{
    RadixTree *tree = NULL;
    int result = 1;

    tree = RadixCreateRadixTree(free, NULL);

    /* Let us have our team here ;-) */
    RadixAddKeyGeneric((uint8_t *)"Victor", 48, tree, NULL);
    RadixAddKeyGeneric((uint8_t *)"Matt", 32, tree, NULL);
    RadixAddKeyGeneric((uint8_t *)"Josh", 32, tree, NULL);
    RadixAddKeyGeneric((uint8_t *)"Margaret", 64, tree, NULL);
    RadixAddKeyGeneric((uint8_t *)"Pablo", 40, tree, NULL);
    RadixAddKeyGeneric((uint8_t *)"Brian", 40, tree, NULL);
    RadixAddKeyGeneric((uint8_t *)"Jasonish", 64, tree, NULL);
    RadixAddKeyGeneric((uint8_t *)"Jasonmc", 56, tree, NULL);
    RadixAddKeyGeneric((uint8_t *)"Nathan", 48, tree, NULL);
    RadixAddKeyGeneric((uint8_t *)"Anoop", 40, tree, NULL);

    RadixRemoveKeyGeneric((uint8_t *)"Nathan", 48, tree);
    RadixRemoveKeyGeneric((uint8_t *)"Brian", 40, tree);
    RadixRemoveKeyGeneric((uint8_t *)"Margaret", 64, tree);

    result &= (RadixFindKeyGeneric((uint8_t *)"Victor", 48, tree) != NULL);
    result &= (RadixFindKeyGeneric((uint8_t *)"Matt", 32, tree) != NULL);
    result &= (RadixFindKeyGeneric((uint8_t *)"Josh", 32, tree) != NULL);
    result &= (RadixFindKeyGeneric((uint8_t *)"Margaret", 64, tree) == NULL);
    result &= (RadixFindKeyGeneric((uint8_t *)"Brian", 40, tree) == NULL);
    result &= (RadixFindKeyGeneric((uint8_t *)"Nathan", 48, tree) == NULL);

    RadixRemoveKeyGeneric((uint8_t *)"Victor", 48, tree);
    RadixRemoveKeyGeneric((uint8_t *)"Josh", 32, tree);
    RadixRemoveKeyGeneric((uint8_t *)"Jasonmc", 56, tree);
    RadixRemoveKeyGeneric((uint8_t *)"Matt", 32, tree);

    result &= (RadixFindKeyGeneric((uint8_t *)"Pablo", 40, tree) != NULL);
    result &= (RadixFindKeyGeneric((uint8_t *)"Jasonish", 64, tree) != NULL);
    result &= (RadixFindKeyGeneric((uint8_t *)"Anoop", 40, tree) != NULL);

    RadixRemoveKeyGeneric((uint8_t *)"Pablo", 40, tree);
    RadixRemoveKeyGeneric((uint8_t *)"Jasonish", 64, tree);
    RadixRemoveKeyGeneric((uint8_t *)"Anoop", 40, tree);

    result &= (RadixFindKeyGeneric((uint8_t *)"Pablo", 40, tree) == NULL);
    result &= (RadixFindKeyGeneric((uint8_t *)"Jasonish", 64, tree) == NULL);
    result &= (RadixFindKeyGeneric((uint8_t *)"Anoop", 40, tree) == NULL);

    result &= (tree->head == NULL);

    RadixReleaseRadixTree(tree);

    return result;
}

int RadixTestIPV6Insertion07(void)
{
    RadixTree *tree = NULL;
    struct sockaddr_in6 servaddr;
    int result = 1;

    tree = RadixCreateRadixTree(free, NULL);

    /* add the keys */
    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "2003:0BF1:5346:BDEA:7422:8713:9124:2315",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    RadixAddKeyIPV6((uint8_t *)&servaddr.sin6_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "BD15:9791:5346:6223:AADB:8713:9882:2432",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    RadixAddKeyIPV6((uint8_t *)&servaddr.sin6_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "1111:A21B:6221:BDEA:BBBA::DBAA:9861",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    RadixAddKeyIPV6((uint8_t *)&servaddr.sin6_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "4444:0BF7:5346:BDEA:7422:8713:9124:2315",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    RadixAddKeyIPV6((uint8_t *)&servaddr.sin6_addr, tree, NULL);

    /* Try to add the prefix that already exists in the tree */
    RadixAddKeyIPV6((uint8_t *)&servaddr.sin6_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "5555:0BF1:ABCD:ADEA:7922:ABCD:9124:2375",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    RadixAddKeyIPV6((uint8_t *)&servaddr.sin6_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "DBCA:ABCD:ABCD:DBCA:1245:2342:1111:2212",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    RadixAddKeyIPV6((uint8_t *)&servaddr.sin6_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "2003:0BF1:5346:1251:7422:1112:9124:2315",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    RadixAddKeyIPV6((uint8_t *)&servaddr.sin6_addr, tree, NULL);

    /* test the existence of keys */
    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "2003:0BF1:5346:BDEA:7422:8713:9124:2315",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV6ExactMatch((uint8_t *)&servaddr.sin6_addr, tree) != NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "BD15:9791:5346:6223:AADB:8713:9882:2432",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV6ExactMatch((uint8_t *)&servaddr.sin6_addr, tree) != NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "1111:A21B:6221:BDEA:BBBA::DBAA:9861",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV6ExactMatch((uint8_t *)&servaddr.sin6_addr, tree) != NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "4444:0BF7:5346:BDEA:7422:8713:9124:2315",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV6ExactMatch((uint8_t *)&servaddr.sin6_addr, tree) != NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "DBCA:ABC2:ABCD:DBCA:1245:2342:1111:2212",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV6ExactMatch((uint8_t *)&servaddr.sin6_addr, tree) == NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "2003:0BF5:5346:1251:7422:1112:9124:2315",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV6ExactMatch((uint8_t *)&servaddr.sin6_addr, tree) == NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "5555:0BF1:ABCD:ADEA:7922:ABCD:9124:2375",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV6ExactMatch((uint8_t *)&servaddr.sin6_addr, tree) != NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "DBCA:ABCD:ABCD:DBCA:1245:2342:1111:2212",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV6ExactMatch((uint8_t *)&servaddr.sin6_addr, tree) != NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "2003:0BF1:5346:1251:7422:1112:9124:2315",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV6ExactMatch((uint8_t *)&servaddr.sin6_addr, tree) != NULL);

    RadixReleaseRadixTree(tree);

    return result;
}

int RadixTestIPV6Removal08(void)
{
    RadixTree *tree = NULL;
    struct sockaddr_in6 servaddr;
    int result = 1;

    tree = RadixCreateRadixTree(free, NULL);

    /* add the keys */
    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "2003:0BF1:5346:BDEA:7422:8713:9124:2315",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    RadixAddKeyIPV6((uint8_t *)&servaddr.sin6_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "BD15:9791:5346:6223:AADB:8713:9882:2432",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    RadixAddKeyIPV6((uint8_t *)&servaddr.sin6_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "1111:A21B:6221:BDEA:BBBA::DBAA:9861",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    RadixAddKeyIPV6((uint8_t *)&servaddr.sin6_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "4444:0BF7:5346:BDEA:7422:8713:9124:2315",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    RadixAddKeyIPV6((uint8_t *)&servaddr.sin6_addr, tree, NULL);

    /* Try to add the prefix that already exists in the tree */
    RadixAddKeyIPV6((uint8_t *)&servaddr.sin6_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "5555:0BF1:ABCD:ADEA:7922:ABCD:9124:2375",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    RadixAddKeyIPV6((uint8_t *)&servaddr.sin6_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "DBCA:ABCD:ABCD:DBCA:1245:2342:1111:2212",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    RadixAddKeyIPV6((uint8_t *)&servaddr.sin6_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "2003:0BF1:5346:1251:7422:1112:9124:2315",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    RadixAddKeyIPV6((uint8_t *)&servaddr.sin6_addr, tree, NULL);

    /* test the existence of keys */
    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "2003:0BF1:5346:BDEA:7422:8713:9124:2315",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    RadixAddKeyIPV6((uint8_t *)&servaddr.sin6_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "8888:0BF1:5346:BDEA:6422:8713:9124:2315",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV6ExactMatch((uint8_t *)&servaddr.sin6_addr, tree) == NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "2006:0BF1:5346:BDEA:7422:8713:9124:2315",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV6ExactMatch((uint8_t *)&servaddr.sin6_addr, tree) == NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "2003:0BF1:5346:BDEA:7422:8713:9124:2315",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV6ExactMatch((uint8_t *)&servaddr.sin6_addr, tree) != NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "BD15:9791:5346:6223:AADB:8713:9882:2432",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    RadixAddKeyIPV6((uint8_t *)&servaddr.sin6_addr, tree, NULL);

    /* test for existance */
    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "1111:A21B:6221:BDEA:BBBA::DBAA:9861",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV6ExactMatch((uint8_t *)&servaddr.sin6_addr, tree) != NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "4444:0BF7:5346:BDEA:7422:8713:9124:2315",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV6ExactMatch((uint8_t *)&servaddr.sin6_addr, tree) != NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "5555:0BF1:ABCD:ADEA:7922:ABCD:9124:2375",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV6ExactMatch((uint8_t *)&servaddr.sin6_addr, tree) != NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "DBCA:ABCD:ABCD:DBCA:1245:2342:1111:2212",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV6ExactMatch((uint8_t *)&servaddr.sin6_addr, tree) != NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "2003:0BF1:5346:1251:7422:1112:9124:2315",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV6ExactMatch((uint8_t *)&servaddr.sin6_addr, tree) != NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "2003:0BF1:5346:BDEA:7422:8713:DDDD:2315",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV6ExactMatch((uint8_t *)&servaddr.sin6_addr, tree) == NULL);

    /* remove keys */
    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "2003:0BF1:5346:BDEA:7422:8713:9124:2315",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    RadixRemoveKeyIPV6((uint8_t *)&servaddr.sin6_addr, tree);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "BD15:9791:5346:6223:AADB:8713:9882:2432",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    RadixRemoveKeyIPV6((uint8_t *)&servaddr.sin6_addr, tree);

    /* test for existance */
    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "2003:0BF1:5346:BDEA:7422:8713:9124:2315",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV6ExactMatch((uint8_t *)&servaddr.sin6_addr, tree) == NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "BD15:9791:5346:6223:AADB:8713:9882:2432",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV6ExactMatch((uint8_t *)&servaddr.sin6_addr, tree) == NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "1111:A21B:6221:BDEA:BBBA::DBAA:9861",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV6ExactMatch((uint8_t *)&servaddr.sin6_addr, tree) != NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "4444:0BF7:5346:BDEA:7422:8713:9124:2315",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV6ExactMatch((uint8_t *)&servaddr.sin6_addr, tree) != NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "5555:0BF1:ABCD:ADEA:7922:ABCD:9124:2375",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV6ExactMatch((uint8_t *)&servaddr.sin6_addr, tree) != NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "DBCA:ABCD:ABCD:DBCA:1245:2342:1111:2212",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV6ExactMatch((uint8_t *)&servaddr.sin6_addr, tree) != NULL);

    /* remove keys */
    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "1111:A21B:6221:BDEA:BBBA::DBAA:9861",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    RadixRemoveKeyIPV6((uint8_t *)&servaddr.sin6_addr, tree);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "4444:0BF7:5346:BDEA:7422:8713:9124:2315",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    RadixRemoveKeyIPV6((uint8_t *)&servaddr.sin6_addr, tree);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "5555:0BF1:ABCD:ADEA:7922:ABCD:9124:2375",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    RadixRemoveKeyIPV6((uint8_t *)&servaddr.sin6_addr, tree);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "DBCA:ABCD:ABCD:DBCA:1245:2342:1111:2212",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    RadixRemoveKeyIPV6((uint8_t *)&servaddr.sin6_addr, tree);

    /* test for existance */
    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "2003:0BF1:5346:BDEA:7422:8713:9124:2315",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV6ExactMatch((uint8_t *)&servaddr.sin6_addr, tree) == NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "BD15:9791:5346:6223:AADB:8713:9882:2432",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV6ExactMatch((uint8_t *)&servaddr.sin6_addr, tree) == NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "1111:A21B:6221:BDEA:BBBA::DBAA:9861",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV6ExactMatch((uint8_t *)&servaddr.sin6_addr, tree) == NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "4444:0BF7:5346:BDEA:7422:8713:9124:2315",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV6ExactMatch((uint8_t *)&servaddr.sin6_addr, tree) == NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "5555:0BF1:ABCD:ADEA:7922:ABCD:9124:2375",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV6ExactMatch((uint8_t *)&servaddr.sin6_addr, tree) == NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "DBCA:ABCD:ABCD:DBCA:1245:2342:1111:2212",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV6ExactMatch((uint8_t *)&servaddr.sin6_addr, tree) == NULL);

    RadixReleaseRadixTree(tree);

    return result;
}

int RadixTestIPV4NetblockInsertion09(void)
{
    RadixTree *tree = NULL;
    struct sockaddr_in servaddr;
    int result = 1;

    tree = RadixCreateRadixTree(free, NULL);

    /* add the keys */
    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.168.1.1", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4((uint8_t *)&servaddr.sin_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.168.1.2", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4((uint8_t *)&servaddr.sin_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.167.1.3", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4((uint8_t *)&servaddr.sin_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.167.1.4", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4((uint8_t *)&servaddr.sin_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "220.168.1.2", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4((uint8_t *)&servaddr.sin_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.168.1.5", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4((uint8_t *)&servaddr.sin_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.168.1.18", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4((uint8_t *)&servaddr.sin_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.168.0.0", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4Netblock((uint8_t *)&servaddr.sin_addr, tree, NULL, 16);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.171.128.0", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4Netblock((uint8_t *)&servaddr.sin_addr, tree, NULL, 24);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.171.192.0", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4Netblock((uint8_t *)&servaddr.sin_addr, tree, NULL, 18);

    if (inet_pton(AF_INET, "192.175.0.0", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4Netblock((uint8_t *)&servaddr.sin_addr, tree, NULL, 16);

    /* test for the existance of a key */
    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.168.1.6", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4BestMatch((uint8_t *)&servaddr.sin_addr, tree) != NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.170.1.6", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4ExactMatch((uint8_t *)&servaddr.sin_addr, tree) == NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.171.128.145", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4BestMatch((uint8_t *)&servaddr.sin_addr, tree) != NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.171.64.6", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4ExactMatch((uint8_t *)&servaddr.sin_addr, tree) == NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.171.191.6", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4ExactMatch((uint8_t *)&servaddr.sin_addr, tree) == NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.171.224.6", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4BestMatch((uint8_t *)&servaddr.sin_addr, tree) != NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.174.224.6", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4ExactMatch((uint8_t *)&servaddr.sin_addr, tree) == NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.175.224.6", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4BestMatch((uint8_t *)&servaddr.sin_addr, tree) != NULL);

    RadixReleaseRadixTree(tree);

    return result;
}

int RadixTestIPV4NetblockInsertion10(void)
{
    RadixTree *tree = NULL;
    RadixNode *node[2];
    struct sockaddr_in servaddr;
    int result = 1;

    tree = RadixCreateRadixTree(free, NULL);

    /* add the keys */
    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "253.192.0.0", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4Netblock((uint8_t *)&servaddr.sin_addr, tree, NULL, 16);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "253.192.235.0", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4Netblock((uint8_t *)&servaddr.sin_addr, tree, NULL, 24);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.167.0.0", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4Netblock((uint8_t *)&servaddr.sin_addr, tree, NULL, 16);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.167.1.4", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4((uint8_t *)&servaddr.sin_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "220.168.0.0", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4Netblock((uint8_t *)&servaddr.sin_addr, tree, NULL, 16);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "253.224.1.5", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4((uint8_t *)&servaddr.sin_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.168.0.0", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4Netblock((uint8_t *)&servaddr.sin_addr, tree, NULL, 16);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.171.128.0", &servaddr.sin_addr) <= 0)
        return 0;
    node[0] = RadixAddKeyIPV4Netblock((uint8_t *)&servaddr.sin_addr, tree, NULL,
                                        24);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.171.128.45", &servaddr.sin_addr) <= 0)
        return 0;
    node[1] = RadixAddKeyIPV4((uint8_t *)&servaddr.sin_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.171.0.0", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4Netblock((uint8_t *)&servaddr.sin_addr, tree, NULL, 18);

    if (inet_pton(AF_INET, "192.175.0.0", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4Netblock((uint8_t *)&servaddr.sin_addr, tree, NULL, 16);

    /* test for the existance of a key */
    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.171.128.53", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4BestMatch((uint8_t *)&servaddr.sin_addr, tree) == node[0]);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.171.128.45", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4ExactMatch((uint8_t *)&servaddr.sin_addr, tree) == node[1]);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.171.128.45", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4BestMatch((uint8_t *)&servaddr.sin_addr, tree) == node[1]);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.171.128.78", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4BestMatch((uint8_t *)&servaddr.sin_addr, tree) == node[0]);

    /* let us remove a netblock */
    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.171.128.0", &servaddr.sin_addr) <= 0)
        return 0;
    RadixRemoveKeyIPV4Netblock((uint8_t *)&servaddr.sin_addr, tree, 24);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.171.128.78", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4BestMatch((uint8_t *)&servaddr.sin_addr, tree) == NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.171.127.78", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4BestMatch((uint8_t *)&servaddr.sin_addr, tree) == NULL);

    RadixReleaseRadixTree(tree);

    return result;
}

int RadixTestIPV4NetblockInsertion11(void)
{
    RadixTree *tree = NULL;
    RadixNode *node = NULL;
    struct sockaddr_in servaddr;
    int result = 1;

    tree = RadixCreateRadixTree(free, NULL);

    /* add the keys */
    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "253.192.0.0", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4Netblock((uint8_t *)&servaddr.sin_addr, tree, NULL, 16);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "253.192.235.0", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4Netblock((uint8_t *)&servaddr.sin_addr, tree, NULL, 24);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.167.0.0", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4Netblock((uint8_t *)&servaddr.sin_addr, tree, NULL, 16);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.167.1.4", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4((uint8_t *)&servaddr.sin_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "220.168.0.0", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4Netblock((uint8_t *)&servaddr.sin_addr, tree, NULL, 16);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "253.224.1.5", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4((uint8_t *)&servaddr.sin_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.168.0.0", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4Netblock((uint8_t *)&servaddr.sin_addr, tree, NULL, 16);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.171.128.0", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4Netblock((uint8_t *)&servaddr.sin_addr, tree, NULL, 24);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.171.128.45", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4((uint8_t *)&servaddr.sin_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.171.0.0", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4Netblock((uint8_t *)&servaddr.sin_addr, tree, NULL, 18);

    if (inet_pton(AF_INET, "192.175.0.0", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4Netblock((uint8_t *)&servaddr.sin_addr, tree, NULL, 16);

    if (inet_pton(AF_INET, "0.0.0.0", &servaddr.sin_addr) <= 0)
        return 0;
    node = RadixAddKeyIPV4Netblock((uint8_t *)&servaddr.sin_addr, tree, NULL, 0);

    /* test for the existance of a key */
    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.171.128.53", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4BestMatch((uint8_t *)&servaddr.sin_addr, tree) != NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.171.128.45", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4BestMatch((uint8_t *)&servaddr.sin_addr, tree) != NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.171.128.78", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4BestMatch((uint8_t *)&servaddr.sin_addr, tree) != NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.171.127.78", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4BestMatch((uint8_t *)&servaddr.sin_addr, tree) == node);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "1.1.1.1", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4BestMatch((uint8_t *)&servaddr.sin_addr, tree) == node);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.255.254.25", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4BestMatch((uint8_t *)&servaddr.sin_addr, tree) == node);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "169.255.254.25", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4BestMatch((uint8_t *)&servaddr.sin_addr, tree) == node);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "0.0.0.0", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4BestMatch((uint8_t *)&servaddr.sin_addr, tree) == node);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "253.224.1.5", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4ExactMatch((uint8_t *)&servaddr.sin_addr, tree) != NULL &&
               RadixFindKeyIPV4ExactMatch((uint8_t *)&servaddr.sin_addr, tree) != node);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "245.63.62.121", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4BestMatch((uint8_t *)&servaddr.sin_addr, tree) != NULL &&
               RadixFindKeyIPV4BestMatch((uint8_t *)&servaddr.sin_addr, tree) == node);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "253.224.1.6", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4BestMatch((uint8_t *)&servaddr.sin_addr, tree) != NULL &&
               RadixFindKeyIPV4BestMatch((uint8_t *)&servaddr.sin_addr, tree) == node);

    /* remove node 0.0.0.0 */
    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "0.0.0.0", &servaddr.sin_addr) <= 0)
        return 0;
    RadixRemoveKeyIPV4Netblock((uint8_t *)&servaddr.sin_addr, tree, 0);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "253.224.1.6", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4BestMatch((uint8_t *)&servaddr.sin_addr, tree) == NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.171.127.78", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4BestMatch((uint8_t *)&servaddr.sin_addr, tree) == NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "1.1.1.1", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4BestMatch((uint8_t *)&servaddr.sin_addr, tree) == NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.255.254.25", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4BestMatch((uint8_t *)&servaddr.sin_addr, tree) == NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "169.255.254.25", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4BestMatch((uint8_t *)&servaddr.sin_addr, tree) == NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "0.0.0.0", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4BestMatch((uint8_t *)&servaddr.sin_addr, tree) == NULL);

    RadixReleaseRadixTree(tree);

    return result;
}

int RadixTestIPV4NetblockInsertion12(void)
{
    RadixTree *tree = NULL;
    RadixNode *node[2];
    struct sockaddr_in servaddr;
    int result = 1;

    tree = RadixCreateRadixTree(free, NULL);

    /* add the keys */
    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "253.192.0.0", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4Netblock((uint8_t *)&servaddr.sin_addr, tree, NULL, 16);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "253.192.235.0", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4Netblock((uint8_t *)&servaddr.sin_addr, tree, NULL, 24);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.167.0.0", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4Netblock((uint8_t *)&servaddr.sin_addr, tree, NULL, 16);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.167.1.4", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4((uint8_t *)&servaddr.sin_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "220.168.0.0", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4Netblock((uint8_t *)&servaddr.sin_addr, tree, NULL, 16);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "253.224.1.5", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4((uint8_t *)&servaddr.sin_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.168.0.0", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4Netblock((uint8_t *)&servaddr.sin_addr, tree, NULL, 16);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.171.128.0", &servaddr.sin_addr) <= 0)
        return 0;
    node[0] = RadixAddKeyIPV4Netblock((uint8_t *)&servaddr.sin_addr, tree, NULL, 24);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.171.128.45", &servaddr.sin_addr) <= 0)
        return 0;
    node[1] = RadixAddKeyIPV4((uint8_t *)&servaddr.sin_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.171.0.0", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4Netblock((uint8_t *)&servaddr.sin_addr, tree, NULL, 18);

    if (inet_pton(AF_INET, "225.175.21.228", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4Netblock((uint8_t *)&servaddr.sin_addr, tree, NULL, 32);

    /* test for the existance of a key */
    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.171.128.53", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4BestMatch((uint8_t *)&servaddr.sin_addr, tree) == node[0]);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.171.128.53", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4ExactMatch((uint8_t *)&servaddr.sin_addr, tree) == NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.171.128.45", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4ExactMatch((uint8_t *)&servaddr.sin_addr, tree) == node[1]);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.171.128.45", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4BestMatch((uint8_t *)&servaddr.sin_addr, tree) == node[1]);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.171.128.45", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4BestMatch((uint8_t *)&servaddr.sin_addr, tree) == node[1]);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.171.128.78", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4BestMatch((uint8_t *)&servaddr.sin_addr, tree) == node[0]);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.171.127.78", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4ExactMatch((uint8_t *)&servaddr.sin_addr, tree) == NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "225.175.21.228", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4ExactMatch((uint8_t *)&servaddr.sin_addr, tree) != NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "225.175.21.224", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4ExactMatch((uint8_t *)&servaddr.sin_addr, tree) == NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "225.175.21.229", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4ExactMatch((uint8_t *)&servaddr.sin_addr, tree) == NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "225.175.21.230", &servaddr.sin_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV4ExactMatch((uint8_t *)&servaddr.sin_addr, tree) == NULL);

    RadixReleaseRadixTree(tree);

    return result;
}

int RadixTestIPV6NetblockInsertion13(void)
{
    RadixTree *tree = NULL;
    struct sockaddr_in6 servaddr;
    int result = 1;

    tree = RadixCreateRadixTree(free, NULL);

    /* add the keys */
    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "2003:0BF1:5346:BDEA:7422:8713:9124:2315",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    RadixAddKeyIPV6((uint8_t *)&servaddr.sin6_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "BD15:9791:5346:6223:AADB:8713:9882:2432",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    RadixAddKeyIPV6((uint8_t *)&servaddr.sin6_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "1111:A21B:6221:BDEA:BBBA::DBAA:9861",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    RadixAddKeyIPV6((uint8_t *)&servaddr.sin6_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "4444:0BF7:5346:BDEA:7422:8713:9124:2315",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    RadixAddKeyIPV6((uint8_t *)&servaddr.sin6_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "5555:0BF1:ABCD:ADEA:7922:ABCD:9124:2375",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    RadixAddKeyIPV6((uint8_t *)&servaddr.sin6_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "DBCA:ABCD:ABCD:DB00:0000:0000:0000:0000",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    RadixAddKeyIPV6Netblock((uint8_t *)&servaddr.sin6_addr, tree, NULL, 56);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "DBCA:ABCD:ABCD:DBAA:1245:2342:1145:6241",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    RadixAddKeyIPV6((uint8_t *)&servaddr.sin6_addr, tree, NULL);

    /* test the existence of keys */
    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "2003:0BF1:5346:BDEA:7422:8713:9124:2315",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV6ExactMatch((uint8_t *)&servaddr.sin6_addr, tree) != NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "BD15:9791:5346:6223:AADB:8713:9882:2432",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV6ExactMatch((uint8_t *)&servaddr.sin6_addr, tree) != NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "1111:A21B:6221:BDEA:BBBA::DBAA:9861",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV6ExactMatch((uint8_t *)&servaddr.sin6_addr, tree) != NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "1111:A21B:6221:BDEA:BBBA::DBAA:9861",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV6BestMatch((uint8_t *)&servaddr.sin6_addr, tree) != NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "4444:0BF7:5346:BDEA:7422:8713:9124:2315",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV6ExactMatch((uint8_t *)&servaddr.sin6_addr, tree) != NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "DBCA:ABC2:ABCD:DBCA:1245:2342:1111:2212",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV6ExactMatch((uint8_t *)&servaddr.sin6_addr, tree) == NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "2003:0BF5:5346:1251:7422:1112:9124:2315",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV6ExactMatch((uint8_t *)&servaddr.sin6_addr, tree) == NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "5555:0BF1:ABCD:ADEA:7922:ABCD:9124:2375",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV6ExactMatch((uint8_t *)&servaddr.sin6_addr, tree) != NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "DBCA:ABCD:ABCD:DBCA:1245:2342:1111:2212",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV6BestMatch((uint8_t *)&servaddr.sin6_addr, tree) != NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "DBCA:ABCD:ABCD:DBAA:1245:2342:1146:6241",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV6BestMatch((uint8_t *)&servaddr.sin6_addr, tree) != NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "DBCA:ABCD:ABCD:DBAA:1245:2342:1356:1241",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV6BestMatch((uint8_t *)&servaddr.sin6_addr, tree) != NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "DBCA:ABCD:ABCD:DAAA:1245:2342:1146:6241",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV6ExactMatch((uint8_t *)&servaddr.sin6_addr, tree) == NULL);


    RadixReleaseRadixTree(tree);

    return result;
}

int RadixTestIPV6NetblockInsertion14(void)
{
    RadixTree *tree = NULL;
    RadixNode *node = NULL;
    struct sockaddr_in6 servaddr;
    int result = 1;

    tree = RadixCreateRadixTree(free, NULL);

    /* add the keys */
    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "2003:0BF1:5346:BDEA:7422:8713:9124:2315",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    RadixAddKeyIPV6((uint8_t *)&servaddr.sin6_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "BD15:9791:5346:6223:AADB:8713:9882:2432",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    RadixAddKeyIPV6((uint8_t *)&servaddr.sin6_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "1111:A21B:6221:BDEA:BBBA::DBAA:9861",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    RadixAddKeyIPV6((uint8_t *)&servaddr.sin6_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "4444:0BF7:5346:BDEA:7422:8713:9124:2315",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    RadixAddKeyIPV6((uint8_t *)&servaddr.sin6_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "5555:0BF1:ABCD:ADEA:7922:ABCD:9124:2375",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    RadixAddKeyIPV6((uint8_t *)&servaddr.sin6_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "DBCA:ABCD:ABCD:DB00:0000:0000:0000:0000",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    RadixAddKeyIPV6Netblock((uint8_t *)&servaddr.sin6_addr, tree, NULL, 56);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "DBCA:ABCD:ABCD:DBAA:1245:2342:1145:6241",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    RadixAddKeyIPV6((uint8_t *)&servaddr.sin6_addr, tree, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "::", &servaddr.sin6_addr) <= 0)
        return 0;
    node = RadixAddKeyIPV6Netblock((uint8_t *)&servaddr.sin6_addr, tree, NULL,
                                     0);

    /* test the existence of keys */
    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "2004:0BF1:5346:BDEA:7422:8713:9124:2315",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV6ExactMatch((uint8_t *)&servaddr.sin6_addr, tree) == NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "2004:0BF1:5346:BDEA:7422:8713:9124:2315",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV6BestMatch((uint8_t *)&servaddr.sin6_addr, tree) == node);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "2004:0BF1:5346:B116:2362:8713:9124:2315",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV6BestMatch((uint8_t *)&servaddr.sin6_addr, tree) == node);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "2004:0B23:3252:BDEA:7422:8713:9124:2341",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV6BestMatch((uint8_t *)&servaddr.sin6_addr, tree) == node);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "DBCA:ABCD:ABCD:DBAA:1245:2342:1145:6241",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV6ExactMatch((uint8_t *)&servaddr.sin6_addr, tree) != NULL &&
               RadixFindKeyIPV6ExactMatch((uint8_t *)&servaddr.sin6_addr, tree) != node);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "DBCA:ABCD:ABCD:DBAA:1245:2342:1145:6241",
                  &servaddr.sin6_addr) <= 0)
        return 0;
    result &= (RadixFindKeyIPV6BestMatch((uint8_t *)&servaddr.sin6_addr, tree) != NULL &&
               RadixFindKeyIPV6BestMatch((uint8_t *)&servaddr.sin6_addr, tree) != node);

    RadixReleaseRadixTree(tree);

    return result;
}

/**
 * \test Check that the best match search works for all the
 *       possible netblocks of a fixed address
 */
int RadixTestIPV4NetBlocksAndBestSearch15(void)
{
    RadixTree *tree = NULL;
    struct sockaddr_in servaddr;
    int result = 1;

    tree = RadixCreateRadixTree(free, NULL);

    uint32_t i = 0;

    uint32_t *user;

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.168.0.1", &servaddr.sin_addr) <= 0) {
        result = 0;
        goto end;
    }

    for (; i <= 32; i++) {
        user = malloc(sizeof(uint32_t));
        if (user == NULL) {
            result = 0;
            goto end;
        }

        *user = i;

        RadixAddKeyIPV4Netblock((uint8_t *)&servaddr.sin_addr, tree, user, i);

        RadixNode *node = RadixFindKeyIPV4BestMatch((uint8_t *)&servaddr.sin_addr, tree);
        if (node == NULL) {
            printf("node == NULL: ");
            result = 0;
            goto end;
        }

        if (node->prefix->user_data_result == NULL) {
            printf("User data == NULL: ");
            result = 0;
            goto end;
        }

        if ( *( (uint32_t*)node->prefix->user_data_result) != i) {
            printf("User data == %d; i == %d: ", *( (uint32_t*)node->prefix->user_data_result), i);
            result = 0;
            goto end;
        }
    }

end:
    RadixReleaseRadixTree(tree);

    return result;
}

/**
 * \test Check that the best match search works for all the
 *       possible netblocks of a fixed address
 */
int RadixTestIPV4NetBlocksAndBestSearch16(void)
{
    RadixTree *tree = NULL;
    struct sockaddr_in servaddr;
    int result = 1;

    tree = RadixCreateRadixTree(free, NULL);

    uint32_t i = 0;

    uint32_t *user;

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.168.1.1", &servaddr.sin_addr) <= 0) {
        result = 0;
        goto end;
    }

    for (; i <= 32; i++) {
        user = malloc(sizeof(uint32_t));
        if (user == NULL) {
            result = 0;
            goto end;
        }

        *user = i;

        RadixAddKeyIPV4Netblock((uint8_t *)&servaddr.sin_addr, tree, user, i);

        RadixNode *node = RadixFindKeyIPV4BestMatch((uint8_t *)&servaddr.sin_addr, tree);
        if (node == NULL) {
            printf("node == NULL: ");
            result = 0;
            goto end;
        }

        if (node->prefix->user_data_result == NULL) {
            printf("User data == NULL: ");
            result = 0;
            goto end;
        }

        if ( *( (uint32_t*)node->prefix->user_data_result) != i) {
            printf("User data == %d; i == %d: ", *( (uint32_t*)node->prefix->user_data_result), i);
            result = 0;
            goto end;
        }
    }

end:
    RadixReleaseRadixTree(tree);

    return result;
}

/**
 * \test Check that the best match search works for all the
 *       possible netblocks of a fixed address
 */
int RadixTestIPV4NetBlocksAndBestSearch17(void)
{
    RadixTree *tree = NULL;
    struct sockaddr_in servaddr;
    int result = 1;

    tree = RadixCreateRadixTree(free, NULL);

    uint32_t i = 0;

    uint32_t *user;

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "10.0.0.1", &servaddr.sin_addr) <= 0) {
        result = 0;
        goto end;
    }

    for (; i <= 32; i++) {
        user = malloc(sizeof(uint32_t));
        if (user == NULL) {
            result = 0;
            goto end;
        }

        *user = i;

        RadixAddKeyIPV4Netblock((uint8_t *)&servaddr.sin_addr, tree, user, i);

        RadixNode *node = RadixFindKeyIPV4BestMatch((uint8_t *)&servaddr.sin_addr, tree);
        if (node == NULL) {
            printf("node == NULL: ");
            result = 0;
            goto end;
        }

        if (node->prefix->user_data_result == NULL) {
            printf("User data == NULL: ");
            result = 0;
            goto end;
        }

        if ( *( (uint32_t*)node->prefix->user_data_result) != i) {
            printf("User data == %d; i == %d: ", *( (uint32_t*)node->prefix->user_data_result), i);
            result = 0;
            goto end;
        }
    }

end:
    RadixReleaseRadixTree(tree);

    return result;
}

/**
 * \test Check that the best match search works for all the
 *       possible netblocks of a fixed address
 */
int RadixTestIPV4NetBlocksAndBestSearch18(void)
{
    RadixTree *tree = NULL;
    struct sockaddr_in servaddr;
    int result = 1;

    tree = RadixCreateRadixTree(free, NULL);

    uint32_t i = 0;

    uint32_t *user;

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "172.26.0.1", &servaddr.sin_addr) <= 0) {
        result = 0;
        goto end;
    }

    for (; i <= 32; i++) {
        user = malloc(sizeof(uint32_t));
        if (user == NULL) {
            result = 0;
            goto end;
        }

        *user = i;

        RadixAddKeyIPV4Netblock((uint8_t *)&servaddr.sin_addr, tree, user, i);

        RadixNode *node = RadixFindKeyIPV4BestMatch((uint8_t *)&servaddr.sin_addr, tree);
        if (node == NULL) {
            printf("node == NULL: ");
            result = 0;
            goto end;
        }

        if (node->prefix->user_data_result == NULL) {
            printf("User data == NULL: ");
            result = 0;
            goto end;
        }

        if ( *( (uint32_t*)node->prefix->user_data_result) != i) {
            printf("User data == %d; i == %d: ", *( (uint32_t*)node->prefix->user_data_result), i);
            result = 0;
            goto end;
        }
    }

end:
    RadixReleaseRadixTree(tree);

    return result;
}

/**
 * \test Check special combinations of netblocks and addresses
 *       on best search checking the returned userdata
 */
int RadixTestIPV4NetBlocksAndBestSearch19(void)
{
    RadixTree *tree = NULL;
    struct sockaddr_in servaddr;
    int result = 1;

    tree = RadixCreateRadixTree(free, NULL);

    uint32_t *user;

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "0.0.0.0", &servaddr.sin_addr) <= 0) {
        result = 0;
        goto end;
    }

    user = malloc(sizeof(uint32_t));
    if (user == NULL) {
        result = 0;
        goto end;
    }

    *user = 100;

    RadixAddKeyIPV4Netblock((uint8_t *)&servaddr.sin_addr, tree, user, 0);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.168.1.15", &servaddr.sin_addr) <= 0) {
        result = 0;
        goto end;
    }

    RadixNode *node = RadixFindKeyIPV4BestMatch((uint8_t *)&servaddr.sin_addr, tree);
    if (node == NULL) {
        printf("node == NULL: ");
        result = 0;
        goto end;
    }

    if (node->prefix->user_data_result == NULL) {
        printf("User data == NULL: ");
        result = 0;
        goto end;
    }

    if ( *( (uint32_t*)node->prefix->user_data_result) != 100) {
        result = 0;
        goto end;
    }

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "177.0.0.0", &servaddr.sin_addr) <= 0) {
        result = 0;
        goto end;
    }

    user = malloc(sizeof(uint32_t));
    if (user == NULL) {
        result = 0;
        goto end;
    }

    *user = 200;

    RadixAddKeyIPV4Netblock((uint8_t *)&servaddr.sin_addr, tree, user, 8);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "177.168.1.15", &servaddr.sin_addr) <= 0) {
        result = 0;
        goto end;
    }

    node = RadixFindKeyIPV4BestMatch((uint8_t *)&servaddr.sin_addr, tree);
    if (node == NULL) {
        printf("node == NULL: ");
        result = 0;
        goto end;
    }

    if (node->prefix->user_data_result == NULL) {
        printf("User data == NULL: ");
        result = 0;
        goto end;
    }

    if ( *( (uint32_t*)node->prefix->user_data_result) != 200) {
        result = 0;
        goto end;
    }

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "178.168.1.15", &servaddr.sin_addr) <= 0) {
        result = 0;
        goto end;
    }

    node = RadixFindKeyIPV4BestMatch((uint8_t *)&servaddr.sin_addr, tree);
    if (node == NULL) {
        printf("node == NULL: ");
        result = 0;
        goto end;
    }

    if (node->prefix->user_data_result == NULL) {
        printf("User data == NULL: ");
        result = 0;
        goto end;
    }

    if ( *( (uint32_t*)node->prefix->user_data_result) != 100) {
        result = 0;
        goto end;
    }

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "177.168.0.0", &servaddr.sin_addr) <= 0) {
        result = 0;
        goto end;
    }

    user = malloc(sizeof(uint32_t));
    if (user == NULL) {
        result = 0;
        goto end;
    }

    *user = 300;

    RadixAddKeyIPV4Netblock((uint8_t *)&servaddr.sin_addr, tree, user, 12);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "177.168.1.15", &servaddr.sin_addr) <= 0) {
        result = 0;
        goto end;
    }

    node = RadixFindKeyIPV4BestMatch((uint8_t *)&servaddr.sin_addr, tree);
    if (node == NULL) {
        printf("node == NULL: ");
        result = 0;
        goto end;
    }

    if (node->prefix->user_data_result == NULL) {
        printf("User data == NULL: ");
        result = 0;
        goto end;
    }

    if ( *( (uint32_t*)node->prefix->user_data_result) != 300) {
        result = 0;
        goto end;
    }

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "177.167.1.15", &servaddr.sin_addr) <= 0) {
        result = 0;
        goto end;
    }

    node = RadixFindKeyIPV4BestMatch((uint8_t *)&servaddr.sin_addr, tree);
    if (node == NULL) {
        printf("node == NULL: ");
        result = 0;
        goto end;
    }

    if (node->prefix->user_data_result == NULL) {
        printf("User data == NULL: ");
        result = 0;
        goto end;
    }

    if ( *( (uint32_t*)node->prefix->user_data_result) != 300) {
        result = 0;
        goto end;
    }

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "177.178.1.15", &servaddr.sin_addr) <= 0) {
        result = 0;
        goto end;
    }

    node = RadixFindKeyIPV4BestMatch((uint8_t *)&servaddr.sin_addr, tree);
    if (node == NULL) {
        printf("node == NULL: ");
        result = 0;
        goto end;
    }

    if (node->prefix->user_data_result == NULL) {
        printf("User data == NULL: ");
        result = 0;
        goto end;
    }

    if ( *( (uint32_t*)node->prefix->user_data_result) != 200) {
        result = 0;
        goto end;
    }

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "197.178.1.15", &servaddr.sin_addr) <= 0) {
        result = 0;
        goto end;
    }

    node = RadixFindKeyIPV4BestMatch((uint8_t *)&servaddr.sin_addr, tree);
    if (node == NULL) {
        printf("node == NULL: ");
        result = 0;
        goto end;
    }

    if (node->prefix->user_data_result == NULL) {
        printf("User data == NULL: ");
        result = 0;
        goto end;
    }

    if ( *( (uint32_t*)node->prefix->user_data_result) != 100) {
        result = 0;
        goto end;
    }


end:
    RadixReleaseRadixTree(tree);

    return result;
}

/**
 * \test Check that the best match search works for all the
 *       possible netblocks of a fixed address
 */
int RadixTestIPV6NetBlocksAndBestSearch20(void)
{
    RadixTree *tree = NULL;
    struct sockaddr_in6 servaddr;
    int result = 1;

    tree = RadixCreateRadixTree(free, NULL);

    uint32_t i = 0;

    uint32_t *user;

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "ABAB:CDCD:ABAB:CDCD:1234:4321:1234:4321", &servaddr.sin6_addr) <= 0) {
        result = 0;
        goto end;
    }

    for (; i <= 128; i++) {
        user = malloc(sizeof(uint32_t));
        if (user == NULL) {
            result = 0;
            goto end;
        }

        *user = i;

        RadixAddKeyIPV6Netblock((uint8_t *)&servaddr.sin6_addr, tree, user, i);

        RadixNode *node = RadixFindKeyIPV6BestMatch((uint8_t *)&servaddr.sin6_addr, tree);
        if (node == NULL) {
            printf("node == NULL: ");
            result = 0;
            goto end;
        }

        if (node->prefix->user_data_result == NULL) {
            printf("User data == NULL: ");
            result = 0;
            goto end;
        }

        if ( *( (uint32_t*)node->prefix->user_data_result) != i) {
            printf("User data == %d; i == %d: ", *( (uint32_t*)node->prefix->user_data_result), i);
            result = 0;
            goto end;
        }
    }

end:
    RadixReleaseRadixTree(tree);

    return result;
}

/**
 * \test Check that the best match search works for all the
 *       possible netblocks of a fixed address
 */
int RadixTestIPV6NetBlocksAndBestSearch21(void)
{
    RadixTree *tree = NULL;
    struct sockaddr_in6 servaddr;
    int result = 1;

    tree = RadixCreateRadixTree(free, NULL);

    uint32_t i = 0;

    uint32_t *user;

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "ff00::1", &servaddr.sin6_addr) <= 0) {
        result = 0;
        goto end;
    }

    for (; i <= 128; i++) {
        user = malloc(sizeof(uint32_t));
        if (user == NULL) {
            result = 0;
            goto end;
        }

        *user = i;

        RadixAddKeyIPV6Netblock((uint8_t *)&servaddr.sin6_addr, tree, user, i);

        RadixNode *node = RadixFindKeyIPV6BestMatch((uint8_t *)&servaddr.sin6_addr, tree);
        if (node == NULL) {
            printf("node == NULL: ");
            result = 0;
            goto end;
        }

        if (node->prefix->user_data_result == NULL) {
            printf("User data == NULL: ");
            result = 0;
            goto end;
        }

        if ( *( (uint32_t*)node->prefix->user_data_result) != i) {
            printf("User data == %d; i == %d: ", *( (uint32_t*)node->prefix->user_data_result), i);
            result = 0;
            goto end;
        }
    }

end:
    RadixReleaseRadixTree(tree);

    return result;
}

/**
 * \test Check that the best match search works for all the
 *       possible netblocks of a fixed address
 */
int RadixTestIPV6NetBlocksAndBestSearch22(void)
{
    RadixTree *tree = NULL;
    struct sockaddr_in6 servaddr;
    int result = 1;

    tree = RadixCreateRadixTree(free, NULL);

    uint32_t i = 0;

    uint32_t *user;

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "ff00::192:168:1:1", &servaddr.sin6_addr) <= 0) {
        result = 0;
        goto end;
    }

    for (; i <= 128; i++) {
        user = malloc(sizeof(uint32_t));
        if (user == NULL) {
            result = 0;
            goto end;
        }

        *user = i;

        RadixAddKeyIPV6Netblock((uint8_t *)&servaddr.sin6_addr, tree, user, i);

        RadixNode *node = RadixFindKeyIPV6BestMatch((uint8_t *)&servaddr.sin6_addr, tree);
        if (node == NULL) {
            printf("node == NULL: ");
            result = 0;
            goto end;
        }

        if (node->prefix->user_data_result == NULL) {
            printf("User data == NULL: ");
            result = 0;
            goto end;
        }

        if ( *( (uint32_t*)node->prefix->user_data_result) != i) {
            printf("User data == %d; i == %d: ", *( (uint32_t*)node->prefix->user_data_result), i);
            result = 0;
            goto end;
        }
    }

end:
    RadixReleaseRadixTree(tree);

    return result;
}

/**
 * \test Check that the best match search works for all the
 *       possible netblocks of a fixed address
 */
int RadixTestIPV6NetBlocksAndBestSearch23(void)
{
    RadixTree *tree = NULL;
    struct sockaddr_in6 servaddr;
    int result = 1;

    tree = RadixCreateRadixTree(free, NULL);

    uint32_t i = 0;

    uint32_t *user;

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "FF00:ABCD:BCDA::ABCD", &servaddr.sin6_addr) <= 0) {
        result = 0;
        goto end;
    }

    for (; i <= 128; i++) {
        user = malloc(sizeof(uint32_t));
        if (user == NULL) {
            result = 0;
            goto end;
        }

        *user = i;

        RadixAddKeyIPV6Netblock((uint8_t *)&servaddr.sin6_addr, tree, user, i);

        RadixNode *node = RadixFindKeyIPV6BestMatch((uint8_t *)&servaddr.sin6_addr, tree);
        if (node == NULL) {
            printf("node == NULL: ");
            result = 0;
            goto end;
        }

        if (node->prefix->user_data_result == NULL) {
            printf("User data == NULL: ");
            result = 0;
            goto end;
        }

        if ( *( (uint32_t*)node->prefix->user_data_result) != i) {
            printf("User data == %d; i == %d: ", *( (uint32_t*)node->prefix->user_data_result), i);
            result = 0;
            goto end;
        }
    }

end:
    RadixReleaseRadixTree(tree);

    return result;
}

/**
 * \test Check special combinations of netblocks and addresses
 *       on best search checking the returned userdata
 */
int RadixTestIPV6NetBlocksAndBestSearch24(void)
{
    RadixTree *tree = NULL;
    struct sockaddr_in6 servaddr;
    int result = 1;

    tree = RadixCreateRadixTree(free, NULL);

    uint32_t *user;

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "::", &servaddr.sin6_addr) <= 0) {
        result = 0;
        goto end;
    }

    user = malloc(sizeof(uint32_t));
    if (user == NULL) {
        result = 0;
        goto end;
    }

    *user = 100;

    RadixAddKeyIPV6Netblock((uint8_t *)&servaddr.sin6_addr, tree, user, 0);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "ABCD::1", &servaddr.sin6_addr) <= 0) {
        result = 0;
        goto end;
    }

    RadixNode *node = RadixFindKeyIPV6BestMatch((uint8_t *)&servaddr.sin6_addr, tree);
    if (node == NULL) {
        printf("node == NULL: ");
        result = 0;
        goto end;
    }

    if (node->prefix->user_data_result == NULL) {
        printf("User data == NULL: ");
        result = 0;
        goto end;
    }

    if ( *( (uint32_t*)node->prefix->user_data_result) != 100) {
        result = 0;
        goto end;
    }

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "ABCD::0", &servaddr.sin6_addr) <= 0) {
        result = 0;
        goto end;
    }

    user = malloc(sizeof(uint32_t));
    if (user == NULL) {
        result = 0;
        goto end;
    }

    *user = 200;

    RadixAddKeyIPV6Netblock((uint8_t *)&servaddr.sin6_addr, tree, user, 8);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "ABCD::1", &servaddr.sin6_addr) <= 0) {
        result = 0;
        goto end;
    }

    node = RadixFindKeyIPV6BestMatch((uint8_t *)&servaddr.sin6_addr, tree);
    if (node == NULL) {
        printf("node == NULL: ");
        result = 0;
        goto end;
    }

    if (node->prefix->user_data_result == NULL) {
        printf("User data == NULL: ");
        result = 0;
        goto end;
    }

    if ( *( (uint32_t*)node->prefix->user_data_result) != 200) {
        printf("User data == %d; i != 200 ", *( (uint32_t*)node->prefix->user_data_result));
        result = 0;
        goto end;
    }

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "DCBA::1", &servaddr.sin6_addr) <= 0) {
        result = 0;
        goto end;
    }

    node = RadixFindKeyIPV6BestMatch((uint8_t *)&servaddr.sin6_addr, tree);
    if (node == NULL) {
        printf("node == NULL: ");
        result = 0;
        goto end;
    }

    if (node->prefix->user_data_result == NULL) {
        printf("User data == NULL: ");
        result = 0;
        goto end;
    }

    if ( *( (uint32_t*)node->prefix->user_data_result) != 100) {
        printf("User data == %d; != 100 ", *( (uint32_t*)node->prefix->user_data_result));
        result = 0;
        goto end;
    }

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "ABCD:ABCD::0", &servaddr.sin6_addr) <= 0) {
        result = 0;
        goto end;
    }

    user = malloc(sizeof(uint32_t));
    if (user == NULL) {
        result = 0;
        goto end;
    }

    *user = 300;

    RadixAddKeyIPV6Netblock((uint8_t *)&servaddr.sin6_addr, tree, user, 12);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "ABCD:ABCD::1", &servaddr.sin6_addr) <= 0) {
        result = 0;
        goto end;
    }

    node = RadixFindKeyIPV6BestMatch((uint8_t *)&servaddr.sin6_addr, tree);
    if (node == NULL) {
        printf("node == NULL: ");
        result = 0;
        goto end;
    }

    if (node->prefix->user_data_result == NULL) {
        printf("User data == NULL: ");
        result = 0;
        goto end;
    }

    if ( *( (uint32_t*)node->prefix->user_data_result) != 300) {
        result = 0;
        goto end;
    }

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "ABCD:AAAA::1", &servaddr.sin6_addr) <= 0) {
        result = 0;
        goto end;
    }

    node = RadixFindKeyIPV6BestMatch((uint8_t *)&servaddr.sin6_addr, tree);
    if (node == NULL) {
        printf("node == NULL: ");
        result = 0;
        goto end;
    }

    if (node->prefix->user_data_result == NULL) {
        printf("User data == NULL: ");
        result = 0;
        goto end;
    }

    if ( *( (uint32_t*)node->prefix->user_data_result) != 300) {
        result = 0;
        goto end;
    }

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "ABAB::1", &servaddr.sin6_addr) <= 0) {
        result = 0;
        goto end;
    }

    node = RadixFindKeyIPV6BestMatch((uint8_t *)&servaddr.sin6_addr, tree);
    if (node == NULL) {
        printf("node == NULL: ");
        result = 0;
        goto end;
    }

    if (node->prefix->user_data_result == NULL) {
        printf("User data == NULL: ");
        result = 0;
        goto end;
    }

    if ( *( (uint32_t*)node->prefix->user_data_result) != 200) {
        result = 0;
        goto end;
    }

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET6, "CABD::1", &servaddr.sin6_addr) <= 0) {
        result = 0;
        goto end;
    }

    node = RadixFindKeyIPV6BestMatch((uint8_t *)&servaddr.sin6_addr, tree);
    if (node == NULL) {
        printf("node == NULL: ");
        result = 0;
        goto end;
    }

    if (node->prefix->user_data_result == NULL) {
        printf("User data == NULL: ");
        result = 0;
        goto end;
    }

    if ( *( (uint32_t*)node->prefix->user_data_result) != 100) {
        result = 0;
        goto end;
    }


end:
    RadixReleaseRadixTree(tree);

    return result;
}


/**
 * \test RadixTestIPV4NetblockInsertion15 insert a node searching on it.
 *       Should always return true but the purposse of the test is to monitor
 *       the memory usage to detect memleaks (there was one on searching)
 */
int RadixTestIPV4NetblockInsertion25(void)
{
    RadixTree *tree = NULL;
    struct sockaddr_in servaddr;
    int result = 1;

    tree = RadixCreateRadixTree(free, NULL);

    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.168.0.0", &servaddr.sin_addr) <= 0)
        return 0;
    RadixAddKeyIPV4Netblock((uint8_t *)&servaddr.sin_addr, tree, NULL, 16);

    /* test for the existance of a key */
    bzero(&servaddr, sizeof(servaddr));
    if (inet_pton(AF_INET, "192.168.128.53", &servaddr.sin_addr) <= 0)
        return 0;

    result &= (RadixFindKeyIPV4BestMatch((uint8_t *)&servaddr.sin_addr, tree) != NULL);

    RadixReleaseRadixTree(tree);

    return result;
}

/**
 * \test RADIX_NODE_USERDATA macro
 */
static int RadixTestUserdataMacro01(void) {
    RadixNode node;
    int result = 0;

    bzero(&node, sizeof(node));

    void *ptr = RADIX_NODE_USERDATA(&node, void);
    if (ptr != NULL) {
        printf("ptr %p, expected NULL: ", ptr);
        goto end;
    }

    result = 1;
end:
    return result;
}

/**
 * \test RADIX_NODE_USERDATA macro
 */
static int RadixTestUserdataMacro02(void) {
    RadixNode node;
    RadixPrefix prefix;
    int result = 0;

    bzero(&node,  sizeof(node));
    bzero(&prefix, sizeof(prefix));

    node.prefix = &prefix;

    void *ptr = RADIX_NODE_USERDATA(&node, void);
    if (ptr != NULL) {
        printf("ptr %p, expected NULL: ", ptr);
        goto end;
    }

    result = 1;
end:
    return result;
}

/**
 * \test RADIX_NODE_USERDATA macro
 */
static int RadixTestUserdataMacro03(void) {
    RadixNode node;
    RadixPrefix prefix;
    int result = 0;
    void *somep = &result;

    bzero(&node,  sizeof(node));
    bzero(&prefix,  sizeof(prefix));

    node.prefix = &prefix;
    prefix.user_data_result = somep;

    void *ptr = RADIX_NODE_USERDATA(&node, void);
    if (ptr != somep) {
        printf("ptr %p, expected %p: ", ptr, somep);
        goto end;
    }

    result = 1;
end:
    return result;
}




void  UtRegisterTest(char *msg, int fun(void), int cnt)
{
  int rc = fun();
  printf("FUN[%d] = %s\n", rc, msg);
}


int  main(void)
{

    UtRegisterTest("RadixTestIPV4Insertion03", RadixTestIPV4Insertion03, 1);
    UtRegisterTest("RadixTestIPV4Removal04", RadixTestIPV4Removal04, 1);
    UtRegisterTest("RadixTestIPV6Insertion07", RadixTestIPV6Insertion07, 1);
    UtRegisterTest("RadixTestIPV6Removal08", RadixTestIPV6Removal08, 1);
    UtRegisterTest("RadixTestIPV4NetblockInsertion09",
                   RadixTestIPV4NetblockInsertion09, 1);
    UtRegisterTest("RadixTestIPV4NetblockInsertion10",
                   RadixTestIPV4NetblockInsertion10, 1);
    UtRegisterTest("RadixTestIPV4NetblockInsertion11",
                   RadixTestIPV4NetblockInsertion11, 1);
    UtRegisterTest("RadixTestIPV4NetblockInsertion12",
                   RadixTestIPV4NetblockInsertion12, 1);
    UtRegisterTest("RadixTestIPV6NetblockInsertion13",
                   RadixTestIPV6NetblockInsertion13, 1);
    UtRegisterTest("RadixTestIPV6NetblockInsertion14",
                   RadixTestIPV6NetblockInsertion14, 1);
    UtRegisterTest("RadixTestIPV4NetBlocksAndBestSearch15",
                   RadixTestIPV4NetBlocksAndBestSearch15, 1);
    UtRegisterTest("RadixTestIPV4NetBlocksAndBestSearch16",
                   RadixTestIPV4NetBlocksAndBestSearch16, 1);
    UtRegisterTest("RadixTestIPV4NetBlocksAndBestSearch17",
                   RadixTestIPV4NetBlocksAndBestSearch17, 1);
    UtRegisterTest("RadixTestIPV4NetBlocksAndBestSearch18",
                   RadixTestIPV4NetBlocksAndBestSearch18, 1);
    UtRegisterTest("RadixTestIPV4NetBlocksAndBestSearch19",
                   RadixTestIPV4NetBlocksAndBestSearch19, 1);
    UtRegisterTest("RadixTestIPV6NetBlocksAndBestSearch20",
                   RadixTestIPV6NetBlocksAndBestSearch20, 1);
    UtRegisterTest("RadixTestIPV6NetBlocksAndBestSearch21",
                   RadixTestIPV6NetBlocksAndBestSearch21, 1);
    UtRegisterTest("RadixTestIPV6NetBlocksAndBestSearch22",
                   RadixTestIPV6NetBlocksAndBestSearch22, 1);
    UtRegisterTest("RadixTestIPV6NetBlocksAndBestSearch23",
                   RadixTestIPV6NetBlocksAndBestSearch23, 1);
    UtRegisterTest("RadixTestIPV6NetBlocksAndBestSearch24",
                   RadixTestIPV6NetBlocksAndBestSearch24, 1);
    UtRegisterTest("RadixTestIPV4NetblockInsertion25",
                   RadixTestIPV4NetblockInsertion25, 1);
    UtRegisterTest("RadixTestUserdataMacro01",
                   RadixTestUserdataMacro01, 1);
    UtRegisterTest("RadixTestUserdataMacro02",
                   RadixTestUserdataMacro02, 1);
    UtRegisterTest("RadixTestUserdataMacro03",
                   RadixTestUserdataMacro03, 1);

    return 0;
}
