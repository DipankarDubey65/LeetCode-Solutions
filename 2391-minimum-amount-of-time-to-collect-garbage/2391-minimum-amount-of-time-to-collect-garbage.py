class Solution:
    def garbageCollection(self, garbage: list[str], travel: list[int]) -> int:

        # P truck
        peakP = 0
        travelP = 0
        lasthouseP = 0

        # M truck
        peakM = 0
        travelM = 0
        lasthouseM = 0

        # G truck
        peakG = 0
        travelG = 0
        lasthouseG = 0

        # Let's travel to the street of houses
        for i in range(len(garbage)):

            # ith house
            currentHouse = garbage[i]

            # Check garbage type present in current house
            for j in range(len(currentHouse)):

                garbageType = currentHouse[j]

                if garbageType == 'P':
                    peakP += 1
                    lasthouseP = i

                if garbageType == 'M':
                    peakM += 1
                    lasthouseM = i

                if garbageType == 'G':
                    peakG += 1
                    lasthouseG = i

        # Calculate travel time for P
        for i in range(lasthouseP):
            travelP += travel[i]

        # Calculate travel time for M
        for i in range(lasthouseM):
            travelM += travel[i]

        # Calculate travel time for G
        for i in range(lasthouseG):
            travelG += travel[i]

        TotalPeackingTime = peakP + peakM + peakG

        TotalTravelTime = travelP + travelM + travelG

        TotalTime = TotalPeackingTime + TotalTravelTime

        return TotalTime