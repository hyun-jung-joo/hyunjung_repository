
public class Book {
	private String title; 
	private String writer;

	public String getTitle() {return title;}
	public String getWriter() {return writer;}
	
	public Book(String title, String writer) {
        this.title = title;
        this.writer = writer;
    }

	public String toString() {
		return "제목 : " + title + ", 저자 : " + writer;
	}
}
