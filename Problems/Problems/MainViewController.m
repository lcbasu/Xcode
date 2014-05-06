
#import "MainViewController.h"

@implementation MainViewController

@synthesize list = _list;
@synthesize button = _button;

- (void)viewDidLoad
{
	[super viewDidLoad];
}

- (void)viewDidUnload
{
	[super viewDidUnload];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
	return (interfaceOrientation != UIInterfaceOrientationPortraitUpsideDown);
}
- (IBAction)buttonTapped:(id)sender
{
    NSLog(@"You tapped on: %@", sender);
    
	[self performSegueWithIdentifier:@"ModalSegue" sender:sender];
}

@end
