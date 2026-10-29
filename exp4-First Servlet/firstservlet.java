import java.io.*;
import javax.servlet.*;

public class FirstServlet extends GenericServlet {

    public void service(ServletRequest req,
            ServletResponse resp)
            throws ServletException, IOException {
        resp.setContentType("text/html");
        PrintWriter pw = resp.getWriter();
        pw.println("<html>");
        pw.println("<head><title>My first Servlet</title></head>");
        pw.println("<body>");
        pw.println("<h2>Welcome To Servlet World!</h2>");
        pw.println("</body>");
        pw.println("</html>");
        pw.close();
    }
}