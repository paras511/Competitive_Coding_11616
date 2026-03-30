from collections import defaultdict, deque

def fox_and_names(words):
    adj = defaultdict(list)
    indegree = {chr(i): 0 for i in range(ord('a'), ord('z') + 1)}

    for i in range(len(words) - 1):
        w1, w2 = words[i], words[i + 1]

        if len(w1) > len(w2) and w1.startswith(w2):
            return "Impossible"

        for c1, c2 in zip(w1, w2):
            if c1 != c2:
                adj[c1].append(c2)
                indegree[c2] += 1
                break

    q = deque()

    for ch in indegree:
        if indegree[ch] == 0:
            q.append(ch)

    topo = []

    while q:
        ch = q.popleft()
        topo.append(ch)

        for neighbor in adj[ch]:
            indegree[neighbor] -= 1
            if indegree[neighbor] == 0:
                q.append(neighbor)

    if len(topo) != 26:
        return "Impossible"

    return "".join(topo)


words = ["baa", "abcd", "abca", "cab", "cad"]
print(fox_and_names(words))