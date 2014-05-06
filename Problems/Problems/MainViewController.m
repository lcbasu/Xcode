
#import "MainViewController.h"

@implementation MainViewController

@synthesize list = _list;

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

- (void)butonTapped:(id)sender
{
	NSLog("You tapped on: %s", sender);

	[self performSegueWithIdentifier:@"ModalSegue" sender:sender];
}

@end
