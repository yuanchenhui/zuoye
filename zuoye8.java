package ych;

import static org.junit.Assert.*;

    import org.junit.Test;

    public class TestTriangle{

        @Test
        public void testIsTriangle1(){
            Triangle t = new Triangle(3,3,3);
            assertEquals(t.getType(t),"Regular");
        }
    
        @Test
        public void testIsTriangle2(){
            // according to the mutant, this test case should fail
            Triangle t = new Triangle(3,2,4);
            assertEquals(t.getType(t),"Scalene");
        }
    
        @Test
        public void testIsTriangle3(){
            Triangle t = new Triangle(3,2,2);
            assertEquals(t.getType(t),"Isoceles");
        }
    }