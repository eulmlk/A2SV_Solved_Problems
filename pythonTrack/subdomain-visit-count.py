class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        visitedSites = {}

        for cpdomain in cpdomains:
            visits, domain = cpdomain.split()
            visits = int(visits)
            domain = domain.split('.')

            for i in range(len(domain)):
                curDomain = '.'.join(domain[i:])
                visitedSites[curDomain] = visitedSites.get(curDomain, 0) + visits
        
        return [f"{visit} {domain}" for domain, visit in visitedSites.items()]
