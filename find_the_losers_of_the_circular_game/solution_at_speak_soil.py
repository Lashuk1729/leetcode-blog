class Solution:
    def circularGameLosers(self, n: int, k: int) -> List[int]:
        losers = set()
        current_friend = 1
        distance_to_next_friend = k

        while True:
            if current_friend in losers:
                break

            losers.add(current_friend)

            next_friend = (current_friend + distance_to_next_friend - 1) % n + 1
            current_friend = next_friend
            distance_to_next_friend += k

        result = []
        for friend in range(1, n+1):
            if friend not in losers:
                result.append(friend)

        return result