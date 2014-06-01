//
//  ImageWallViewController.m
//  FBParse
//

#import "ImageWallViewController.h"

@interface ImageWallTableImageCell ()
@property (nonatomic, strong) IBOutlet UIImageView *image;
@property (nonatomic, strong) IBOutlet UIImageView *profilePicture;
@property (nonatomic, strong) IBOutlet UILabel *lblUploadedBy;
@property (nonatomic, strong) IBOutlet UILabel *lblUploadedDate;
@end

@implementation ImageWallTableImageCell
- (IBAction) shareImage:(id)sender
{
}
@end

@interface ImageWallTableCommentCell ()
@property (nonatomic, strong) IBOutlet UIImageView *profilePicture;
@property (nonatomic, strong) IBOutlet UILabel *comment;
@end

@implementation ImageWallTableCommentCell

@end

@interface ImageWallTableNewCommentCell () <UITextFieldDelegate>
@property (nonatomic, strong) IBOutlet UITextField *txtComment;
@end

@implementation ImageWallTableNewCommentCell
- (BOOL) textFieldShouldReturn:(UITextField *)textField
{
	return YES;
}
@end


@interface ImageWallViewController ()

@end

@implementation ImageWallViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
}

#pragma mark UI Actions from Storyboard

- (IBAction) logoutPressed:(id)sender
{
    [self.navigationController popViewControllerAnimated:YES];
}

- (IBAction) uploadPressed:(id)sender
{
	// Seque to the Image Uploader
	[self performSegueWithIdentifier:@"UploadImage" sender:self];
}


#pragma mark Table View Datasource

- (NSInteger) numberOfSectionsInTableView:(UITableView *)tableView
{
	return 0;
}

- (NSInteger) tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
	return 0;
}


- (CGFloat) tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section
{
	return 100;
}

- (UIView *) tableView:(UITableView *)tableView viewForHeaderInSection:(NSInteger)section
{
	// The header View is actually a UITableViewCell defined in the Storyboard
	static NSString *ImageCellIdentifier = @"ImageCell";
    ImageWallTableImageCell *imageCell = (ImageWallTableImageCell *)[tableView dequeueReusableCellWithIdentifier:ImageCellIdentifier];
    
    return imageCell;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
	static NSString *CommentCellIdentifier = @"CommentCell";
	ImageWallTableCommentCell *commentCell = (ImageWallTableCommentCell *)[tableView dequeueReusableCellWithIdentifier:CommentCellIdentifier];
	
    return commentCell;
}

@end
