#ifndef INCLUDED_AEGIS_AFTT_TIMEZONE
#define INCLUDED_AEGIS_AFTT_TIMEZONE

namespace aftt {

struct Timezone
{
    enum Region {
        Region_LOCAL,
        Region_GMT,
        Region_AMERICA_NEW_YORK,
        Region_EUROPE_LONDONG,
        Region_ASIA_TOKYO
    };

    static bool isDST(Region region);

    static int currentOffset(Region region);

    static int currentOffset(Region region, bool& isDST);
};

} // namespace

#endif // INCLUDED
