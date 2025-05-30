class Solution {
    private int[] getDistances(int[] edges, int start) {
        int n = edges.length;
        int[] dist = new int[n];
        Arrays.fill(dist, -1);
        int curr = start;
        int d = 0;
        while(curr != -1 && dist[curr] == -1){
            dist[curr] = d++;
            curr = edges[curr];
        }
        return dist;
    }
    public int closestMeetingNode(int[] edges, int node1, int node2) {
        int[] dist1 = getDistances(edges, node1);
        int[] dist2 = getDistances(edges, node2);
        int answer = -1;
        int minMaxDist = Integer.MAX_VALUE;
        for(int i = 0; i < edges.length; i++){
            if(dist1[i] != -1 && dist2[i] != -1){
                int maxDist = Math.max(dist1[i], dist2[i]);
                if(maxDist < minMaxDist){
                    minMaxDist = maxDist;
                    answer = i;
                }
            }
        }
        return answer;
    }
}