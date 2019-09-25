

class Traverse{
	double maxCost;
	boolean[] defaultFlags;
	int[] path;
	int[] resPath;
	double[][] costMartrix;
	int num;
	public Traverse(int num,double[][] cost) {
		maxCost=Double.POSITIVE_INFINITY;
		this.num=num;
		defaultFlags=new boolean[num];
		for(int i=0;i<num;i++) {
			defaultFlags[i]=false;
		}
		path=new int[num];
		resPath=new int[num];
		costMartrix=cost;
		recur(num, 0, defaultFlags);
	}
	public void recur(int n,double cost,boolean[] flags) {
		if(n==1) {
			for(int i=0;i<num;i++) {
				if(!flags[i]) {
					int c1=path[num-n-1];
					int c2=i;
					double tmp=costMartrix[c1][c2]+cost;
					if(tmp>=maxCost) {
						//System.out.println("tmp="+tmp);
						return;
					}
					path[num-1]=i;
					maxCost=tmp;
					System.arraycopy(path, 0, resPath, 0, num);
					
					//System.out.println();
					return;
				}
			}
		}
	
		
		for(int i=0;i<num;i++) {
			//System.arraycopy(flags, 0, nFlags, 0, num);
			if(!flags[i]) {
				boolean[] nFlags=new boolean[num];
				System.arraycopy(flags, 0, nFlags, 0, num);
				nFlags[i]=true;
				if(num==n) {
					path[0]=i;
					recur(n-1, 0, nFlags);
				}
				else {
					int c1=path[num-n-1];
					int c2=i;
					//System.out.println(c1+"->"+c2+":"+costMartrix[c1][c2]);
					double fee=cost+costMartrix[c1][c2];				
					if(fee>=maxCost) {
						//System.out.println("fee="+fee);
						return;
					}
					path[num-n]=i;
					//for(int j=0;j<num-n+1;j++) {
					//	System.out.print(path[j]+"\t");
					//}
					//System.out.println("cost="+cost+"fee"+fee);
					recur(n-1, fee, nFlags);
				}
			}
		}
	}
	public void show() {
		System.out.println("cost:"+maxCost);
		for(int i=0;i<num;i++) {
			System.out.print(resPath[i]+1);
			System.out.print("\t");
		}
	}
}


public class MainClass {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		double[][] costMartrix= {{0,100,1},{100,0,2},{1,2,0}};
		Traverse traverse=new Traverse(3, costMartrix);
		traverse.show();
	}

}
