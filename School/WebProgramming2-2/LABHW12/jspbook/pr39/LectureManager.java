package jspbook.pr39;

import java.util.*;

public class LectureManager {
	private static final int times = 6;
	private static final int days = 5;
	private int[][] typeMatrix = new int[times][days];
	private int[][] titleMatrix = new int[times][days];
	private int[][] spanMatrix = new int[times][days];
	
	ArrayList<LectureBean> lectureList = new ArrayList<LectureBean>();
	
	public LectureManager() {
		int l, m;
		for(l = 0; l < times; l++) {
			for(m = 0; m < days; m++) {
				typeMatrix[l][m] = 0;
				titleMatrix[l][m] = -1;
				spanMatrix[l][m] = 1;
			}
		}
	}
	
	public List<LectureBean> getLectureList(){
		return lectureList;
	}
	
	public void add(LectureBean lbean) {
		lectureList.add(lbean);
	}
	
	public void buildMatrix() {
		int i;
		for(i = 0; i < lectureList.size(); i++) {
			LectureBean lb = lectureList.get(i);
			int p = lb.getTime() - 1; 
			int x = lb.getDay();
				
			typeMatrix[p][x] = lb.getType() + 1;
			titleMatrix[p][x] = lb.getTitle();
			if(lb.getConsecutive() > 1) {
				spanMatrix[p][x] = lb.getConsecutive();
				int size = lb.getConsecutive();
				for(int k = p + 1; k < p + size; k++)
					spanMatrix[k][x] = 0;
			}
		}
		
		System.out.println("typeMatrix");
		printMatrix(typeMatrix);
		System.out.println("titleMatrix");
		printMatrix(titleMatrix);
		System.out.println("spanMatrix");
		printMatrix(spanMatrix);
		System.out.println();
	}
	
	public static void printMatrix(int[][] matrix) {
		int r, c;
		System.out.println("{");
		for(r = 0; r < times; r++) {
			for(c = 0; c < days; c++) {
				System.out.print(matrix[r][c] + " ");
			}
			System.out.println();
		}
		System.out.println("}");
	}
}

