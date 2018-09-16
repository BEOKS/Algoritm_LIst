import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main{
    public static int[] topologicalSort(LinkedList<Integer>[] graph,int[] indegree,int[] time){
        int len=indegree.length-1;
        int[] result=new int[len+1];
        Queue<Integer> queue=new LinkedList<Integer>();
        for(int i=1;i<=len;i++){
            if(indegree[i]==0){
                queue.add(i);
                result[i]=time[i];
            }
        }

        while(!queue.isEmpty()){
            int v=queue.poll();
            for(int next : graph[v]){
                result[next]=Math.max(result[next],result[v]+time[next]);
                if(--indegree[next]==0){
                    ((LinkedList<Integer>) queue).add(next);
                }
            }
        }
        return result;
    }
}
