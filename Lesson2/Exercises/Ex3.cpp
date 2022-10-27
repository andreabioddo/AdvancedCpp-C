/**
 * The class RiskyTime is not secure. Mainly because the main attributes of the class are public.
 * That allows user to set values that couldn't be right to rapresent time. 
 * For example, an user could set the minute value to 34 that doesn't rapresent an hour. Same 
 * examples could be done for minutes and seconds. 
 * The best manage the class is putting the attributes as private and allow changes only by
 * methods that control input values.
 * 
 */

