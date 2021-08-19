class Point{
    int x; 
    int y;
    Point(int x, int y){
        this.x = x;
        this.y = y;
    }
}
class Solution {
    public int largestRectangleArea(int[] heights) {
        int n = heights.length;
        ArrayList<Integer> a = new ArrayList<>();
        ArrayList<Integer> b = new ArrayList<>();
        b = NSR(heights);
        a = NSL(heights);
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = Math.max(ans, (b.get(i) - a.get(i) - 1)*heights[i]);
        }
        return ans;
    }
    
    static ArrayList<Integer> NSR(int[]heights){
        int n = heights.length;
        ArrayList<Integer> a = new ArrayList<>();
        Stack<Point> st = new Stack<>();
        for(int i = heights.length - 1; i >= 0; i--){
            if(st.size() == 0){
                a.add(n);
            }
            else if(st.size() > 0 && st.peek().x < heights[i]){
                a.add(st.peek().y);
            }
            else{
                while(st.size() > 0 && st.peek().x >= heights[i]){
                    st.pop();
                }
                if(st.size() == 0){
                    a.add(n);
                }
                else{
                    a.add(st.peek().y);
                }
            }
            
            st.push(new Point(heights[i], i));
        }
        
        Collections.reverse(a);
        return a;
    }
    
     static ArrayList<Integer> NSL(int[]heights){
        int n = heights.length;
        ArrayList<Integer> a = new ArrayList<>();
        Stack<Point> st = new Stack<>();
        for(int i = 0; i < n; i++){
            if(st.size() == 0){
                a.add(-1);
            }
            else if(st.size() > 0 && st.peek().x < heights[i]){
                a.add(st.peek().y);
            }
            else{
                while(st.size() > 0 && st.peek().x >= heights[i]){
                    st.pop();
                }
                if(st.size() == 0){
                    a.add(-1);
                }
                else{
                    a.add(st.peek().y);
                }
            }
            
            st.push(new Point(heights[i], i));
        }
        
    
        return a;
    }
    
    
}