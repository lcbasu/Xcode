
#import <UIKit/UIKit.h>

@interface MainViewController : UIViewController

@property (nonatomic, retain) NSArray *list;
@property (nonatomic, retain) IBOutlet UIButton *button;

- (IBAction)buttonTapped:(id)sender;

@end
