//
//  FBLoginViewController.m
//  FBParse
//

#import "FBLoginViewController.h"

@interface FBLoginViewController ()
@property (nonatomic, strong) IBOutlet UIButton *btnLogin;
@property (nonatomic, strong) IBOutlet UIActivityIndicatorView *activityLogin;
@end

@implementation FBLoginViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {

    }
    return self;
}

- (void) viewDidLoad
{
	[super viewDidLoad];
}

// Outlet for FBLogin button
- (IBAction) loginPressed:(id)sender
{

}

@end
