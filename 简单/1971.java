/*
@可爱抱抱呀
执行用时：98 ms, 在所有 Java 提交中击败了26.97%的用户
内存消耗：149.9 MB, 在所有 Java 提交中击败了13.89%的用户
2022年3月23日 15:55
*/
class Solution {
    public boolean validPath(int n, int[][] edges, int source, int destination) {
        List<Integer> path[]=new List[n];
        boolean cameBefore[]=new boolean[n];
        for(int i=-0;i<n;i++){path[i]=new ArrayList<>();}
        for(int i=0;i<edges.length;i++){
            path[edges[i][0]].add(edges[i][1]);
            path[edges[i][1]].add(edges[i][0]);
        }
        return hasPath(source,destination,cameBefore,path);
    }
    boolean hasPath(int p,int des,boolean cameBefore[],List<Integer> path[]){
        if(p==des){return true;}
        if(cameBefore[p]){return false;}
        cameBefore[p]=true;
        for(int i=0;i<path[p].size();i++){if(hasPath(path[p].get(i),des,cameBefore,path)){return true;}}
        return false;
    }
}